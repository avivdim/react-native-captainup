import CaptainUp

@objc(Captainup)
class Captainup: RCTEventEmitter, CPTListener, CPTUserListener {

  private var authResolve: RCTPromiseResolveBlock?
  private var authReject: RCTPromiseRejectBlock?
  private var isInitialized = false
  private var properties: CPTPropertiesUser?
  private var actionableUser: CPTActionableUser?

  override init() {
    super.init()
    NotificationCenter.default.addObserver(
      self,
      selector: #selector(appDidBecomeActive),
      name: UIApplication.didBecomeActiveNotification,
      object: nil
    )
    NotificationCenter.default.addObserver(
      self,
      selector: #selector(appDidEnterBackground),
      name: UIApplication.didEnterBackgroundNotification,
      object: nil
    )
  }

  deinit {
    NotificationCenter.default.removeObserver(self)
  }

  override func supportedEvents() -> [String]! {
    return ["onBadgesAchieved", "onLevelUpdate"]
  }

  @objc private func appDidBecomeActive() {
    CPT.applicationDidBecomeActive()
  }

  @objc private func appDidEnterBackground() {
    CPT.applicationDidEnterBackground()
  }

  // MARK: - JS Methods

  @objc(initialize:mobileToken:resolver:rejecter:)
  func initialize(
    apiKey: String,
    mobileToken: String,
    resolve: @escaping RCTPromiseResolveBlock,
    reject: @escaping RCTPromiseRejectBlock
  ) {
    if isInitialized {
      resolve(nil)
      return
    }
    properties = CPTPropertiesUserBuilder.build { builder in
      builder.active = true
      builder.url = "https://captainup.com"
      builder.apiKey = apiKey
      builder.mobileToken = mobileToken
    }
    isInitialized = true
    resolve(nil)
  }

  @objc(authenticate:userName:resolver:rejecter:)
  func authenticate(
    userId: String,
    userName: String,
    resolve: @escaping RCTPromiseResolveBlock,
    reject: @escaping RCTPromiseRejectBlock
  ) {
    guard isInitialized, let props = properties else {
      reject("CAPTAINUP_NOT_INITIALIZED", "Call initialize() before authenticate()", nil)
      return
    }
    authResolve = resolve
    authReject = reject
    let integrationUser = CPTIntegrationUserBuilder.build { builder in
      builder.userId = userId
      builder.name = userName
    }
    // Must add listener before calling authenticate (per SDK docs)
    CPT.addListener(self)
    CPT.authenticate(integrationUser, withProperties: props, error: nil)
  }

  @objc(sendAction:resolver:rejecter:)
  func sendAction(
    actionName: String,
    resolve: @escaping RCTPromiseResolveBlock,
    reject: @escaping RCTPromiseRejectBlock
  ) {
    guard let user = actionableUser else {
      reject("CAPTAINUP_NOT_AUTHENTICATED", "No authenticated user. Call authenticate() first.", nil)
      return
    }
    let entity = CPTActionableEntityBuilder.build { builder in
      builder.type = "action"
      builder.name = actionName
      builder.entityDescription = ""
      builder.url = ""
    }
    let action = CPTActionBuilder.build { builder in
      builder.name = actionName
      builder.entity = entity
    }
    user.performAction(action)
    resolve(nil)
  }

  // MARK: - CPTListener

  func onAuthenticationDone(_ user: CPTActionableUser) {
    DispatchQueue.main.async {
      self.actionableUser = user
      // Register as CPTUserListener to receive badge/level events
      user.addListener(self)
      self.authResolve?(nil)
      self.authResolve = nil
      self.authReject = nil
    }
  }

  // MARK: - CPTUserListener

  func onUser(_ user: CPTUser, achievedBadges badges: [CPTBadge]) {
    let payload = badges.map { badge -> [String: Any] in
      return [
        "id": badge.badgeId,
        "name": badge.name,
        "description": badge.badgeDescription
      ]
    }
    sendEvent(withName: "onBadgesAchieved", body: payload)
  }

  func onUser(_ user: CPTUser, achievedLevels levels: [CPTLevel]) {
    let payload = levels.map { level -> [String: Any] in
      return [
        "number": level.ordinalNumber,
        "name": level.name
      ]
    }
    sendEvent(withName: "onLevelUpdate", body: payload)
  }

  // Required by CPTUserListener (no @optional in header)
  func onUser(_ user: CPTUser, newRewardAvailableForClaim reward: CPTReward, withBadge badge: CPTBadge) {}

  // Optional CPTUserListener stubs
  func onUser(_ user: CPTUser, badgeProgress map: CPTBadgeProgressDictionary) {}
  func onUser(_ user: CPTUser, error: Error?) {}
}
