//
//  User.h
//  captainup_sdk
//
//  Created by David Azriel on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef User_h
#define User_h

#import "CPTObject.h"
#import "CPTBadgeProgressDictionary.h"
#import "CPTLevel.h"
#import "CPTAction.h"
#import "CPTApplication.h"
#import "CPTAcquiredAsset.h"
#import "CPTAvailableReward.h"

/**
 The player resource provides information about an app's users. Users share basic information and
 details such as the user name and the avatar image across all Captain Up apps,
 while users' progress in each app is completely independent.
 */
@protocol CPTUser <CPTObject>

/**
 Captain up user app specific id
 */
@property (nonatomic, readonly, nonnull) NSString *userId;

/**
 client assigned user id
 */
@property (nonatomic, readonly, nonnull) NSString *clientUserID;

/**
 The access token can be used in other Captain Up requests to identify the user that is
 currently logged in to the app. For example, this will grant permissions to see the user's private
 activities or to post actions for the user.
 The access token will be empty if the app enabled the "Secure User Integration" option and
 the requested user data was not signed (see CPTIntegrationUserBuilder::setSignature).
 */
@property (nonatomic, readonly, nonnull) NSString *accessToken;

/**
 user name
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 user image url
 */
@property (nonatomic, readonly, nonnull) NSString *imageURL;

/**
 user monthly points
 */
@property (nonatomic, readonly) CPTPoint monthlyPoints;

/**
 user weekly points
 */
@property (nonatomic, readonly) CPTPoint weeklyPoints;

/**
 user daily points
 */
@property (nonatomic, readonly) CPTPoint dailyPoints;

/**
 The user's position in all the leaderboards
 returns a map between the type of leaderboard and the the user's position.
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,NSNumber*> *leaderboardPositions;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTAction>> *privateActivities;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTAction>> *publicActivities;

/**
 All of the badges the user has any progress on, including the completed ones.
 @return a map where the keys are the IDs (String) of the badges and the the values are the badge's progress information.
 */
@property (nonatomic, readonly, nonnull) CPTBadgeProgressDictionary *badgeProgress;

/**
 Description
 */
@property (nonatomic, readonly) NSUInteger totalActionCount;

/**
 Information on the total number of times the user has done the app actions.
 The keys here are based on your app action identifiers.
 @return A map between the action name and its counter (never <code>null</code>).
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,NSNumber*> *actionCounters;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSString* levelID;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,NSNumber*> *currencies;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTAcquiredAsset>> *acquiredAssets;

/**
 List of available rewards that user can claim.
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTAvailableReward>> *availableRewards;

/**
 get user current level

 @return return CPTLevel object
 */
-(nullable id<CPTLevel>)getLevel;

/**
 get user next level

 @return return CPTLevel object
 */
-(nullable id<CPTLevel>)getNextLevel;

/**
 Description

 @param application CPTApplication object
 */
-(void)setApplication:(nonnull id<CPTApplication>)application;

/**
 get unavailable segmented badge ids

 @return return NSArray of badge ids
 */
-(nonnull NSArray<NSString*>*)getUnavailableSegmentedBadgesIDs;

/**
 get unavailable segmented asset ids

 @return return NSArray of asset ids
 */
-(nonnull NSArray<NSString*>*)getUnavailableSegmentedAssetIDs;

/**
 unread inbox items

 @return return CPTAction object array
 */
-(nonnull NSArray<id<CPTAction>>*)getBaseUnreadInboxItems;

@end

#endif /* User_h */
