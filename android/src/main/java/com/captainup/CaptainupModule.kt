package com.captainup

// NOTE: The import paths below (com.captainup.sdk.*) are based on the SDK documentation.
// Verify the actual package names against the real framework.jar by opening it in
// Android Studio or running: javap -classpath android/libs/framework.jar <ClassName>
import com.captainup.sdk.CaptainUp
import com.captainup.sdk.CaptainUpPropertiesBuilder
import com.captainup.sdk.IntegrationUserBuilder
import com.captainup.sdk.listener.AuthenticateCaptainUpListener
import com.captainup.sdk.listener.BadgeCaptainUpUserListener
import com.captainup.sdk.listener.LevelCaptainUpUserListener
import com.captainup.sdk.model.ActionableUser
import com.captainup.sdk.model.Badge
import com.captainup.sdk.model.Level
import com.captainup.sdk.model.User

import com.facebook.react.bridge.Arguments
import com.facebook.react.bridge.LifecycleEventListener
import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.WritableArray
import com.facebook.react.bridge.WritableMap
import com.facebook.react.modules.core.DeviceEventManagerModule

class CaptainupModule(reactContext: ReactApplicationContext) :
  ReactContextBaseJavaModule(reactContext),
  LifecycleEventListener {

  // Pending authentication Promise — stored across the async callback boundary.
  @Volatile private var authPromise: Promise? = null

  // Guards against double-initialization.
  @Volatile private var isInitialized: Boolean = false

  // Stored SDK properties so authenticate() can reuse them.
  private var captainUpProps: com.captainup.sdk.CaptainUpProperties? = null

  init {
    // Register for Activity lifecycle so we can forward onResume/onPause to the SDK.
    reactContext.addLifecycleEventListener(this)
  }

  override fun getName(): String = NAME

  // ---------- JS-facing methods ----------

  @ReactMethod
  fun initialize(apiKey: String, mobileToken: String, promise: Promise) {
    if (isInitialized) {
      promise.resolve(null)
      return
    }
    try {
      captainUpProps = CaptainUpPropertiesBuilder()
        .setActive(true)
        .setUrl("https://captainup.com")
        .setApiKey(apiKey)
        .setMobileToken(mobileToken)
        .build()
      isInitialized = true
      promise.resolve(null)
    } catch (e: Exception) {
      promise.reject("CAPTAINUP_INIT_ERROR", e.message, e)
    }
  }

  @ReactMethod
  fun authenticate(userId: String, userName: String, promise: Promise) {
    if (!isInitialized || captainUpProps == null) {
      promise.reject(
        "CAPTAINUP_NOT_INITIALIZED",
        "Call initialize() before authenticate()"
      )
      return
    }

    if (CaptainUp.isConnected()) {
      // Already authenticated — resolve immediately.
      promise.resolve(null)
      return
    }

    val integrationUser = IntegrationUserBuilder()
      .setId(userId)
      .setName(userName)
      .build()

    authPromise = promise

    try {
      CaptainUp.authenticate(
        reactApplicationContext,
        captainUpProps!!,
        integrationUser,
        object : AuthenticateCaptainUpListener {
          override fun onAuthenticationDone(actionableUser: ActionableUser) {
            val p = authPromise ?: return
            authPromise = null

            // Attach badge and level listeners to the authenticated user.
            actionableUser.addListener(object : BadgeCaptainUpUserListener {
              override fun onAchievedBadges(user: User, achievedBadges: Collection<Badge>) {
                emitBadgesAchieved(achievedBadges)
              }
            })

            actionableUser.addListener(object : LevelCaptainUpUserListener {
              override fun onLevelUpdate(user: User, levels: List<Level>) {
                emitLevelUpdate(levels)
              }
            })

            p.resolve(null)
          }
        }
      )
    } catch (e: Exception) {
      val p = authPromise
      authPromise = null
      p?.reject("CAPTAINUP_AUTH_ERROR", e.message, e)
    }
  }

  @ReactMethod
  fun sendAction(actionName: String, promise: Promise) {
    val loggedInUser = try {
      CaptainUp.getLoggedInUser()
    } catch (e: Exception) {
      promise.reject("CAPTAINUP_ACTION_ERROR", "Failed to get logged-in user: ${e.message}", e)
      return
    }

    if (loggedInUser == null) {
      promise.reject(
        "CAPTAINUP_NOT_AUTHENTICATED",
        "No authenticated user. Call authenticate() first."
      )
      return
    }

    try {
      loggedInUser.doAction(actionName)
      promise.resolve(null)
    } catch (e: Exception) {
      promise.reject("CAPTAINUP_ACTION_ERROR", e.message, e)
    }
  }

  // ---------- Lifecycle forwarding ----------

  override fun onHostResume() {
    try { CaptainUp.onResume() } catch (_: Exception) {}
  }

  override fun onHostPause() {
    try { CaptainUp.onPause() } catch (_: Exception) {}
  }

  override fun onHostDestroy() {
    authPromise?.reject("CAPTAINUP_DESTROYED", "Module destroyed before authentication completed")
    authPromise = null
  }

  // ---------- Event emission ----------

  private fun emitBadgesAchieved(badges: Collection<Badge>) {
    val array: WritableArray = Arguments.createArray()
    for (badge in badges) {
      val map: WritableMap = Arguments.createMap()
      // NOTE: Getter names (id, name, description) must be verified against the real JAR.
      map.putString("id", badge.id ?: "")
      map.putString("name", badge.name ?: "")
      map.putString("description", badge.description ?: "")
      array.pushMap(map)
    }
    emit("onBadgesAchieved", array)
  }

  private fun emitLevelUpdate(levels: List<Level>) {
    val array: WritableArray = Arguments.createArray()
    for (level in levels) {
      val map: WritableMap = Arguments.createMap()
      // NOTE: Getter names (number, name) must be verified against the real JAR.
      map.putInt("number", level.number)
      map.putString("name", level.name ?: "")
      array.pushMap(map)
    }
    emit("onLevelUpdate", array)
  }

  private fun emit(eventName: String, data: Any?) {
    reactApplicationContext
      .getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter::class.java)
      .emit(eventName, data)
  }

  companion object {
    const val NAME = "Captainup"
  }
}
