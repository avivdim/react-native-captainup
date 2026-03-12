//
//  CPTFacade.h
//  CaptainUp
//
//  Created by David Azriel on 25/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTFacade_h
#define CPTFacade_h

#import "CPTObject.h"
#import "CPTListener.h"
#import "CPTIntegrationUser.h"
#import "CPTLeaderboardTime.h"
#import "CPTQuery.h"
#import "CPTLeaderboardResponse.h"
#import "CPTApplication.h"
#import "CPTUser.h"
#import "CPTActionableUser.h"
#import "CPTSocialFeedResponse.h"
#import "CPTBadge.h"
#import "CPTAsset.h"
#import "CPTPropertiesUser.h"


/**
 * The main class to access the Captain Up Framework.
 * To work with this class, always maintain the following workflow:
 * <ol>
 *     <li>Use addListener</li>
 *     <li>Call connect</li>
 *     <li>After receiving onAfterConnect event, authenticate you App's user with captain up using authenticate</li>
 *     <li>Even before the authentication is complete, you can now query the application and its leaderboards</li>
 *     <li>After receiving onAuthenticationDoneyou can get the logged in user, perform action on it, and listen to its events</li>
 * </ol>
 */
@interface CPT : NSObject

/**
 * Adds a listener to Captain Up events. The type of event or events being listened to is
 * determined by the interfaces implemented by the <code>listener</code> parameter.
 * Supported events:
 * <ul>
 *     <li>Connection Established</li>
 *     <li>User Authenticated</li>
 * </ul>
 * @param listener The <code>listener</code>
 *                 can implement multiple interfaces and thus will be registered to all events it supports.
 */
+ (void)addListener:(nonnull id<CPTListener>)listener;

/**
 * Removes a listener from this user instance.
 * @param listener the listener object to be removed.
 */
+ (void)removeListener:(nonnull id<CPTListener>)listener;

/**
 * Initializes Captain Up objects. This must be called before any other methods (such as authenticate.
 * If the connection succeeds and there's a listener registered, the onAfterConnect will be called.
 * If there was an error connection, and there's a listener registered, 
 * the onError will be called. Make sure you call addListener before connect.
 * For most cases, there's no need to distinguish between the "connect" and "authenticate" flows.
 * @param properties the name of the captain up configuration file. By default use "captainup_config". The file must exist in the aplpication's main bundle.
 */
+ (void)connectWithProperties:(nonnull id<CPTPropertiesUser>)properties error:(NSError * _Nullable * _Nullable)error;

/**
 * Authenticates a user to Captain Up. If the user does not exist in Captain Up yet, it will be
 * created. In any case, if the authentication was successful and there is a
 * listener registered the onAuthenticationDone will be called. If there was an error connection, and there's a
 * listener registered, the onError will be called. Must be called after a successful call to connect.
 * If the Captain Up Configuration files define a non-empty "login_action", that action will be
 * automatically invoked by the framework.
 * The Framework supports only one logged in user. If you require more than that, use the CPTConnectionFactory
 * object to create a new connection.
 * @param user the user to authenticate and log in.
 */
+ (void)authenticate:(nonnull id<CPTIntegrationUser>)user;

/**
 * Connects and Authenticates a user to Captain Up. If the connection succeeds and there's a registered listener 
 * the onAfterConnect will be called.
 * If the user does not exist in Captain Up yet, it will be created.
 * In any case, if the authentication was successful and there is a listener registered, the onAuthenticationDone will be called.
 * If there was an error connection, and there's a listener registered, the onError will be called. 
 * Make sure you call addListener before connect.
 * <br /> <br />
 * If the Captain Up Configuration files define a non-empty "login_action", that action will be
 * automatically invoked by the framework.
 * <br /> <br />
 * The Framework supports only one logged in user. If you require more than that, use the CPTConnectionFactory
 * object.
 * @param user the user to authenticate and log in.
 * @param properties the name of the captain up configuration file. By default use "captainup_config". The file must exist in the aplpication's main bundle.
 * @param error any error related to reading the configuraiton file
 */
+ (void)authenticate:(nonnull id<CPTIntegrationUser>)user withProperties:(nonnull id<CPTPropertiesUser>)properties error:(NSError * _Nullable * _Nullable)error;



+ (void)queryLeaderboard:(CPTLeaderboardTime)time forUser:(nullable NSString *)userId with:(nonnull id<CPTQuery>)query callback:(RESPONSE_CALLBACK(id<CPTLeaderboardResponse>))callback;
/**
 * Get the app social feed
 * @param callback response callback
 */
+ (void)querySocialFeed:(RESPONSE_CALLBACK(id<CPTSocialFeedResponse>))callback;

/**
 *  Get a player feed by Player ID
 *
 * @param playerId - The player ID (Captain Up ID)
 * @param callback response callback
 */
+ (void)queryPlayerFeed:(nonnull NSString *)playerId callback:(RESPONSE_CALLBACK(id<CPTSocialFeedResponse>))callback;

+ (void)getUser:(nonnull NSString *)userId callback:(RESPONSE_CALLBACK(id<CPTUser>))callback;

/**
 * Checks whether or not you are already connected to Captain Up.
 * @return <code>true</code> if and only if you are already connected to Captain Up.
 * @see connect
 */
+ (BOOL)isConnected;

/**
 * Checks whether or not you already authenticated a user with the Captain Up SDK.
 * @return <code>true</code> if and only if you successfully authenticated a user.
 */
+ (BOOL)isAuthenticated;

/**
 * Returns all the current connected application's settings, including information on the action
 * settings, levels, badges and etc.
 * The call to connect must have completed successfully before calling this method.
 * @return the application that was connected to.
 */
+ (nonnull id<CPTApplication>)application;

/**
 * Returns the logged in user. If there is not a yet a logged in user, a user object will still
 * be returned. This "empty user" will not contain any information about the user (such as
 * his\her name or ID), but it still allows the developer to start listening for events and
 * perform actions. Once you successfully {@link #authenticate(Context, int, IntegrationUser) authenticated}
 * a user, any pending actions will be sent and processed and any events will be raised accordingly.
 * Note: if the was a disconnect (for exmaple, the client's network is down), <b>after</b> a successful
 * connection, the user will contain the latest information we've got. Any actions performed while
 * in this "disconnect" state will generate errors to the user listeners..
 * It is your responsibility to aggregate these failed actions and they will not be retried.
 * @return the logged in user.
 */
+ (nonnull id<CPTActionableUser>)loggedInUser;

/**
 * Refreshes the Captain Up connection and logged in user (if any).
 * If there was a logged in user, then the user's information will be updated within the same
 * ActionableUser instance. Any listeners connected to the user will be invoked to
 * reflect changed because of the update.
 * This is an asynchronous operation that will trigger listeners. Once the refresh is done the
 * registered listeners will be invoked.
 */
+ (void)refresh;

/**
 * Disconnect from Captain Up. Can be used to log in a new user.
 * To log in with a new user (when already logged in), call disconnect
 * and than [CPT authenticate:integrationUser withFile:@"captainup_config" error:nil];
 */
+ (void)disconnect;

/**
 * Sets the application language, use this function to set your user localization.
 * Localization will affect all badges and levels names and description.
 * This function must be called before calling @see authenticate(Context context, int configId, final IntegrationUser user) or @see connect(Context context, int configId)
 *
 * @param languageCode the user language code
 */
+ (void)setLanguageCode:(nonnull NSString*)languageCode;

+ (void)setCountry:(nonnull NSString*)country;

+ (void)setCurrency:(nonnull NSString*)currency;

+ (nonnull NSDictionary<NSString*,id<CPTBadge>>*)getSegmentedBadges;

+ (nonnull NSDictionary<NSString*,id<CPTAsset>>*)getSegmentedAssets;

+ (nonnull NSDictionary<NSString*,id<CPTAsset>>*)getSegmentedAssetsByType:(CPTAssetType)assetType;

+ (void)applicationDidBecomeActive;

+(void)applicationDidEnterBackground;

@end

#endif /* CPTFacade_h */
