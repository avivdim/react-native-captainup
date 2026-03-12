//
//  CPTActionableUser.h
//  CaptainUp
//
//  Created by David Azriel on 13/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTActionableUser_h
#define CPTActionableUser_h

#import "CPTUser.h"
#import "CPTUserListener.h"
#import "CPTAction.h"
#import "CPTInbox.h"
#import "CPTNotificationsQueue.h"
#import "CPTBadge.h"
#import "CPTReward.h"
#import "CPTClaimResponse.h"
#import "CPTUserResponse.h"
#import "CPTCreateAcquireResponse.h"

/**
 Description
 */
@protocol CPTActionableUser <CPTUser>

/**
 Adds a listener to this user instance. The type of event of events being listened to is
 determined by the exact protocols implemented by the listener parameter.

 @param listener listener CPTUserListener
 */
- (void)addListener:(nonnull id<CPTUserListener>)listener;

/**
 Remove listner

 @param listener listener CPTUserListener
 */
- (void)removeListener:(nonnull id<CPTUserListener>)listener;

/**
 Perform action

 @param action action CPTAction
 */
- (void)performAction:(nonnull id<CPTAction>)action;

/**
 @brief Returns a list of rewards that are ready to be claimed.
 You can present these reward to the user with a 'claim' button, when user pressed 'claim' you can use `reward.claim(callback)`
 to claim.
 
 @return NSArray list of badge rewards or an empty list if no rewards are available.
 */
- (nonnull NSArray<id<CPTReward>>*)getUnclaimedRewardsArray;

/**
 @brief Returns a list of rewards that are ready to be claimed (unclaimed rewards from achieved badges).
 You can present these reward to the user with a 'claim' button, when user pressed 'claim' you can use `claimReward`
 to claim.

 @return NSDictionary map of all reward that the user can claim (where key is the badge object and value is the associated reward),
 or an empty Map in case no rewards are available.
 */
- (nonnull NSDictionary<id<CPTBadge>,id<CPTReward>>*)getUnclaimedRewards;

/**
 @brief Giving a Badge object, returns a list of associated rewards that are ready to be claimed.
        Can be used when achieving a badge to get all the badge's associated rewards.
 @param badge CPTBadge to check rewards in. (Must be an achieved badge)
 @return NSArray list of badge rewards or an empty list if no rewards are available.
 */
- (nonnull NSArray<id<CPTReward>>*)getUnclaimedRewards:(nonnull id<CPTBadge>)badge;

/**
 Checks if the badge's reward is available to claim for the current user.
 @return true if badge contains a reward, badge was achieved and reward was never claimed,
 or (in case of repeatable badges with rewards), if badge
 was achieved more times than reward was claimed,
 otherwise returns false.
 */
-(BOOL)isRewardClaimable:(nonnull id<CPTBadge>)badge;

/**
 Preforms Synchronous claim action
 
 @param reward CPTReward The Reward to claim
 */
- (void)claim:(nonnull id<CPTReward>)reward;

/**
 Performs Asynchronus claim action

 @param reward CTPReward The reward to claim
 @param callback void(^)(id<CPTClaimResponse> response, NSError *error)
 */
- (void)claim:(nonnull id<CPTReward>)reward withCallback:(RESPONSE_CALLBACK(id<CPTClaimResponse>))callback;

/**
 @brief Performs a claim action on a badge with reward
 @param badge CPTBadge with reward
 */
- (void)claimReward:(nonnull id<CPTBadge>)badge __attribute((deprecated("use reward.claim() method")));

/**
 @brief Performs an Async claim action on a badge with reward, accepts a callback
 @param badge CPTBadge with reward
 @param callback void(^)(id<CPTClaimResponse> response, NSError *error) with reward
 */
- (void)claimReward:(nonnull id<CPTBadge>)badge withCallback:(RESPONSE_CALLBACK(id<CPTClaimResponse>))callback __attribute((deprecated("use reward.claim(callback) method")));

/**
 @brief Performs a claim action on a badge with reward
 @param badge CPTBadge with reward
 @param reward CPTReward The reward to claim
 */
- (void)claimReward:(nonnull id<CPTBadge>)badge andReward:(nonnull id<CPTReward>)reward __attribute((deprecated("use reward.claim() method")));

/**
 @brief Perform an Async claim action on a specific reward, accepts callback
 @param badge CPTBadge with the reward
 @param reward CPTReward The reward to claim
 @param callback void(^)(id<CPTClaimResponse> response, NSError *error) with reward
 */
- (void)claimReward:(nonnull id<CPTBadge>)badge andReward:(nonnull id<CPTReward>)reward withCallback:(RESPONSE_CALLBACK(id<CPTClaimResponse>))callback __attribute((deprecated("use reward.claim(callback) method")));

/**
Acquire an asset, you will receive the Asset object in the `CPTUserListener` listener.
in some cases (for example when user does not have enough currency or stock is limited) call will return an error, you can listen to error
events to catch that error, or supply a callback.
This method is asynchronous.
@param asset The id<CPTAsset> to acquire
@return CPTCreateAcquireResponse
 */
- (nonnull id<CPTCreateAcquireResponse>)acquireAsset:(nonnull id<CPTAsset>)asset ;

/**
Acquire an asset, you will receive the Asset object in the `CPTUserListener` listener.
in some cases (for example when user does not have enough currency or stock is limited) call will return an error, you can listen to error
events to catch that error, or supply a callback.
This method is asynchronous.
@param asset The id<CPTAsset> to acquire
@param dynamicOptionsForReward NSDictionary<NSString *, id> to assign Dynamic Options for reward
@return CPTCreateAcquireResponse
 */
- (nonnull id<CPTCreateAcquireResponse>)acquireAsset:(nonnull id<CPTAsset>)asset dynamicOptionsForReward:(nullable NSDictionary<NSString *, id> *)dynamicOptionsForReward;

/**
 Acquire an asset, you will receive the Asset object in the `CPTUserListener` listener.
 in some cases (for example when user does not have enough currency or stock is limited) call will return an error.
 This method is asynchronous.
@param asset id<CPTAsset> to acquire
@param callback CPTCreateAcquireResponse
 */
- (void)acquireAssetAsync:(nonnull id<CPTAsset>)asset withCallback:(RESPONSE_CALLBACK(id<CPTCreateAcquireResponse>))callback;

/**
 Acquire an asset, you will receive the Asset object in the `CPTUserListener` listener.
 in some cases (for example when user does not have enough currency or stock is limited) call will return an error.
 This method is asynchronous.
@param asset id<CPTAsset> to acquire
@param dynamicOptionsForReward NSDictionary<NSString *, id> to assign Dynamic Options for reward
@param callback CPTCreateAcquireResponse
 */

- (void)acquireAssetAsync:(nonnull id<CPTAsset>)asset
  dynamicOptionsForReward:(nullable NSDictionary<NSString *, id> *)dynamicOptionsForReward
             withCallback:(RESPONSE_CALLBACK(id<CPTCreateAcquireResponse>))callback;



/**
 Update user name

 @param name new name of user
 */
- (void)updateName:(nonnull NSString*)name;

/**
 Update user name

 @param name user name
 @param callback user details updated callback
 */
- (void)updateName:(nonnull NSString*)name withCallback:(RESPONSE_CALLBACK(id<CPTUserResponse>))callback;

/**
 Update user Image url

 @param url user profile pic url
 */
- (void)updateImageUrl:(nonnull NSString*)url;

/**
 Update user Image url

 @param url user profile url
 @param callback user prfoile url updated callback
 */
- (void)updateImageUrl:(nonnull NSString*)url withCallback:(RESPONSE_CALLBACK(id<CPTUserResponse>))callback;

/**
 Inbox
 */
@property (nonatomic, readonly, nonnull) id<CPTInbox> inbox;

/**
 Notification queue
 */
@property (nonatomic, readonly, nonnull) id<CPTNotificationsQueue> notificationsQueue;

@end

#endif /* CPTActionableUser_h */
