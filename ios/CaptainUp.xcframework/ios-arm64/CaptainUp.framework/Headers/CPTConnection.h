//
//  CaptainUpConnection.h
//  captainup_sdk
//
//  Created by David Azriel on 09/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef CaptainUpConnection_h
#define CaptainUpConnection_h

#import "CPTApplicationResponse.h"
#import "CPTIntegrationUser.h"
#import "CPTUserResponse.h"
#import "CPTActionsResponse.h"
#import "CPTQuery.h"
#import "CPTLeaderboardTime.h"
#import "CPTLeaderboardResponse.h"
#import "CPTAuthenticatedConnection.h"
#import "CPTSocialFeedResponse.h"

/**
 A connection to the Captain Up Platform.
 An instance of this interface should be instantiated using {@link CaptainUpConnectionFactory#createConnection(String, String, String)}.
 Contains method that does not require authentication to be used (aside from the App ID and Mobile Token, that was used to create the connection).
 */
@protocol CPTConnection <NSObject>

/**
 Returns all the current connected application's settings, including information on the action
 settings, levels, badges and etc.
 current thread until the request returns.
 @param callback a callback that will contain the response and any exception that might
                  have risen during the execution.
 */
- (void)retrieveApplication:(RESPONSE_CALLBACK(id<CPTApplicationResponse>))callback;

/**
 Allows you to either update an existing user account or create a new user account,
 based on a unique user ID that you create and maintain in your system.
 The response will contain the updated user information.
 thread until the request returns.
 @param user the user details to create or update. The user can be created using the
              {@link com.captainup.android.model.IntegrationUserBuilder IntegrationUserBuilder}
 @param callback a callback that will contain the response and any exception that might
                  have risen during the execution.
 */
- (void)addOrUpdateIntegrationUser:(nonnull id<CPTIntegrationUser>)user callback:(RESPONSE_CALLBACK(id<CPTUserResponse>))callback;

/**
 Returns several actions and information about the users associated with them.
 Only returns <b>public</b> actions, since there is no authenticated user.
 Use this method to request the public actions of any user in your application.
 thread until the request returns.
 @param playerId the ID of the player whose actions are requested
 @param query query parameters. To create a query object use {@link QueryBuilder}
 @param callback a callback that will contain the response and any exception that might
                 have risen during the execution.
 */
- (void)queryActionsForPlayer:(nonnull NSString *)playerId query:(nonnull id<CPTQuery>)query callback:(RESPONSE_CALLBACK(id<CPTSocialFeedResponse>))callback;

/**
 Returns several users from the requested leaderboard, including general information on t
 hose users, and their position in the leaderboard.
 @param time the type of the leaderboard (according to the time limit on the leaderboard)
 @param playerId the user id for the user we want to focus the leaderboard on.
                  Useful for showing a specific user’s standing in the leaderboard.
                  If playerId is not <code>null</code>, the skip query parameter will be dismissed.
                  The response will be a list of the players around the given player,
                  with a maximum of half the users above the player and the rest below.
 @param query query parameters. To create a query object use {@link QueryBuilder}.
               <ul>
                   <li>skip - The number of users to skip when returning the users.
                              If skip is above the total number of users, an empty list of users will be returned.</li>
                  <li>limit - The maximum number of users to return in the results.
                               Can be between 10 and 100. </li>
                   <li>extended - If set to true, will return extended information on each user. </li>
               </ul>
 @return a response object that may either contain an error code or the leaderboard's details
 */
- (void)queryLeaderboard:(CPTLeaderboardTime)time forPlayer:(nullable NSString *)playerId withQuery:(nonnull id<CPTQuery>)query callback:(RESPONSE_CALLBACK(id<CPTLeaderboardResponse>))callback;


/**
 Returns several actions and information about the users associated with them.
 Only returns <b>public</b> actions, since there is no authenticated user.
 Use this method to request the public actions of any user in your application.
 This method is preferred over <code>queryActions</code> since this will not block the current
 thread until the request returns.
 @param query query parameters. To create a query object use {@link QueryBuilder}
 @param callback a callback that will contain the response and any exception that might
                 have risen during the execution.
 */
- (void)querySocialFeed:(nonnull id<CPTQuery>) query callback:(RESPONSE_CALLBACK(id<CPTSocialFeedResponse>))callback;

/**
 Returns information about the specific user requested, including general information about
 the user (name, Facebook link, avatar, etc.) and information about the user's progress
 (current level, number of points, missions and progress).
 @param userId the user's captain-up ID
 @param callback callback that will contain the response and any exception that might
                 have risen during the execution.
 @see #retrieveUser(String)
 */
- (void)retrieveUser:(nonnull NSString *)userId callback:(RESPONSE_CALLBACK(id<CPTUserResponse>))callback;


/**
 Returns an {@link AuthenticatedCaptainUpConnection authenticated connection} to captain up.
 Some operations are only available after authentication.
 @param user the user to authenticate. This user can be acquired from the addOrUpdateIntegrationUser.
 @return an {@link AuthenticatedCaptainUpConnection authenticated connection} to captain up.
 @see #addOrUpdateIntegrationUser(IntegrationUser)
 @see #addOrUpdateIntegrationUserAsync(IntegrationUser, ResponseCallback)
 */
- (nonnull id<CPTAuthenticatedConnection>)authenticate:(nonnull id<CPTUser>)user;

/**
 Use this function for setting your user localization,
 setting language code will affect your application badges and levels as localized in the admins panel.
 this function must be called *before calling @see authenticate(User user) or connect.
 
 This function is used internally by CaptainUpManager object
 @param languageCode language code
 */
- (void)setLanguageCode:(nonnull NSString*) languageCode;

/**
 Use this function for setting your user country,
 setting country will affect your application currency conversion ratio.
 this function must be called *before calling @see authenticate(User user) or connect.
 
 This function is used internally by CaptainUpManager object
 @param country country code string
 */
- (void)setCountry:(nonnull NSString*) country;

/**
 Use this function for setting your user currency,
 setting currency will affect your application currency conversion ratio.
 this function must be called *before calling @see authenticate(User user) or connect.
 
 This function is used internally by CaptainUpManager object
 @param currency currency string
 */
- (void)setCurrency:(nonnull NSString*) currency;

/**
Call this method to keep socket connected. Main use would be connect immidialty whne applicaion becomes acrive
 */
-(void)keepSocketConnected;

/**
 Call this method to disconnect socket.
 */
-(void)disconnectSocket;

@end

#endif /* CaptainUpConnection_h */
