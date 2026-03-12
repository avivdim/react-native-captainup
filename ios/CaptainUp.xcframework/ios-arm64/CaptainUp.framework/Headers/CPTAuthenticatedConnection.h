//
//  AuthenticatedConnection.h
//  captainup_sdk
//
//  Created by David Azriel on 09/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef AuthenticatedConnection_h
#define AuthenticatedConnection_h

#import "CPTActionType.h"
#import "CPTQuery.h"
#import "CPTActionsResponse.h"
#import "CPTAction.h"
#import "CPTCreateActionResponse.h"
#import "CPTClaimResponse.h"
#import "CPTBadge.h"
#import "CPTReward.h"
#import "CPTSocketNotificationListener.h"
#import "CPTCreateAcquireResponse.h"

@protocol CPTConnection;

/**
 Description
 */
@protocol CPTAuthenticatedConnection <NSObject,CPTConnection>

/**
 Creates a new action and adds it to your app. When you create new actions, several things happen:
 <ul>
    <li>The user the action is associated with, and other users, may receive points from doing this action, based on the action settings. </li>
    <li>The user may get promoted to a new level because of the points he or she received from the action.</li>
    <li>The user might achieve a badges, or multiple badges.</li>
    <li>When one of these things happen, it will be reported in the response.</li>
 </ul>

 @param action the action to create. The action can be obtained using
                {@link com.captainup.android.model.ActionBuilder ActionBuilder}.
 @param callback a callback that will contain the response and any exception that might
                  have risen during the execution. The response may contain an erro code or the
                  changes objects from the operation.
 */
- (void)createAction:(nonnull id<CPTAction>)action callback:(RESPONSE_CALLBACK(id<CPTCreateActionResponse>))callback;

/**
 * Returns several actions and information about the users associated with them.
 * Can return any type of actions for the authenticated user.
 * @param actionType the type of the action
 * @param query query parameters. To create a query object use {@link QueryBuilder}
 * @param callback a callback that will contain the response and any exception that might
 *                 have risen during the execution.
 * @see #queryActions(ActionType, Query)
 */
- (void)queryActionsOfType:(CPTActionType)actionType query:(nonnull id<CPTQuery>)query callback:(RESPONSE_CALLBACK(id<CPTActionsResponse>))callback;

/**
 Retrieves the unread inbox notification items

 @param callback List of unread inbox items
 */
-(void)queryUnreadInboxWithCallback:(RESPONSE_CALLBACK(id<CPTActionsResponse>))callback;


/**
 * Removes notifications of the specified type (private or inbox) – either all notifications,
 * or only a specified number.
 * @param actionType the requested notification's type.
 *                   They only allowed values are {@link ActionType#PRIVATE} and {@link ActionType#INBOX} -
 *                   it is not possible to delete only the public notifications. Private
 *                   notifications also include the public ones.
 * @param query query parameters. To create a query object use {@link QueryBuilder}
 * @param callback
 */
- (void)deleteNotificationsOfType:(CPTActionType)actionType query:(nonnull id<CPTQuery>)query callback:(RESPONSE_CALLBACK(id<CPTActionsResponse>))callback;

/**
 * Removes a specific notification of the specified type (private or inbox) – either all notifications,
 * or only a specified number.
 * @param actionType the requested notification's type.
 *                   They only allowed values are {@link ActionType#PRIVATE} and {@link ActionType#INBOX} -
 *                   it is not possible to delete only the public notifications. Private
 *                   notifications also include the public ones.
 * @param query query parameters. To create a query object use {@link QueryBuilder}
 * @param messageID the ID of the notification to delete {@link Action#getID()}
 *
 * @return a response object that may either contain an error code or the list of remaining
 *         notifications of the given type.
 * @throws CaptainUpException
 * @throws IllegalArgumentException if the actionType is PUBLIC
 */
 
-(nonnull id<CPTActionsResponse>)deleteNotificationOfType:(CPTActionType)actionType query:(nonnull id<CPTQuery>)query messageID:(nonnull NSString*)messageID;

/**
 * Removes a specific notification of the specified type (private or inbox) – either all notifications,
 * or only a specified number.
 * This method is preferred over {@link #deleteNotifications(ActionType, Query)}
 * since this will not block the current thread until the request returns.
 * @param actionType the requested notification's type.
 *                   They only allowed values are {@link ActionType#PRIVATE} and {@link ActionType#INBOX} -
 *                   it is not possible to delete only the public notifications. Private
 *                   notifications also include the public ones.
 * @param query query parameters. To create a query object use {@link QueryBuilder}
 * @param messageID the ID of the notification to delete {@link Action#getID()}
 * @param callback a callback that will contain the response and any exception that might
 *                 have risen during the execution.
 */

-(void)deleteNotificationOfTypeAsync:(CPTActionType)actionType query:(nonnull id<CPTQuery>)query messageID:(nonnull NSString*)messageID callback:(RESPONSE_CALLBACK(id<CPTActionsResponse>))callback;

/**
 * Claim reward synchronous
 * @param reward CPTRewad object
 * @return id<CPTClaimResponse>
 */
- (nonnull id<CPTClaimResponse>)claim:(nonnull id<CPTReward>)reward;

/**
 * Claim a reward asynchronous
 *
 * @param reward CPTRewad object
 * @param callback response listener
 */
- (void)claim:(nonnull id<CPTReward>)reward withCallback:(RESPONSE_CALLBACK(id<CPTClaimResponse>))callback;

/**
 * Claim reward synchronous
 * @param badge the badge with the reward to claim. (Must be a badge with a reward.)
 * @return id<CPTClaimResponse>
 */
- (nonnull id<CPTClaimResponse>)claimReward:(nonnull id<CPTBadge>)badge;

/**
 * Claim reward synchronous
 * @param badge the badge with the reward to claim. (Must be a badge with a reward.)
 * @param reward Bage obejct
 * @return id<CPTClaimResponse>
 */
- (nonnull id<CPTClaimResponse>)claimReward:(nonnull id<CPTBadge>)badge andReward:(nonnull id<CPTReward>)reward;

/**
 * Claim a reward from a Badge with reward (has its hasReward() function returns true).
 * Once a reward is claimed, it cannot be claimed again (will result in a callback error)
 * callback will contain the claimed reward (you can use callback.getRewards() function).
 *
 * This method is asynchronous.
 * @param badge badge with reward to be claimed
 * @param callback response listener
 */
- (void)claimRewardAsync:(nonnull id<CPTBadge>)badge withCallback:(RESPONSE_CALLBACK(id<CPTClaimResponse>))callback;

/**
 * Claim a reward from a Badge with reward (has its hasReward() function returns true).
 * Once a reward is claimed, it cannot be claimed again (will result in a callback error)
 * callback will contain the claimed reward (you can use callback.getRewards() function).
 *
 * This method is asynchronous.
 * @param badge badge with reward to be claimed
 * @param reward reward to be claimed
 * @param callback response listener
 */
- (void)claimRewardAsync:(nonnull id<CPTBadge>)badge andReward:(nonnull id<CPTReward>)reward withCallback:(RESPONSE_CALLBACK(id<CPTClaimResponse>))callback;

/**
 * Acquire an asset, you will receive the Asset object in the `CPTUserListener` listener.
 * in some cases (for example when user does not have enough currency or stock is limited) call will return an error, you can listen to error
 * events to catch that error, or supply a callback.
 * This method is asynchronous.
 * @param asset The id<CPTAsset> to acquire
 * @return CPTCreateAcquireResponse
 */
- (nonnull id<CPTCreateAcquireResponse>)acquireAsset:(nonnull id<CPTAsset>)asset;

/**
 * Acquire an asset, you will receive the Asset object in the `CPTUserListener` listener.
 * in some cases (for example when user does not have enough currency or stock is limited) call will return an error, you can listen to error
 * events to catch that error, or supply a callback.
 * This method is asynchronous.
 * @param asset The id<CPTAsset> to acquire
 * @param dynamicOptionsForReward NSDictionary<NSString *, id> to assign Dynamic Options for reward
 * @return CPTCreateAcquireResponse
 */
- (nonnull id<CPTCreateAcquireResponse>)acquireAsset:(nonnull id<CPTAsset>)asset dynamicOptionsForReward:(nullable NSDictionary<NSString *, id> *)dynamicOptionsForReward;

/**
 * Acquire an asset, you will receive the Asset object in the `CPTUserListener` listener.
 * in some cases (for example when user does not have enough currency or stock is limited) call will return an error.
 * This method is asynchronous.
 * @param asset id<CPTAsset> to acquire
 * @param callback CPTCreateAcquireResponse
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
 * Used to listen to notification events from actions (used by framework
 * @param listener CPTSocketNotificationListener
 */
- (void)setListener:(nonnull id<CPTSocketNotificationListener>)listener;

@end

#endif /* AuthenticatedConnection_h */
