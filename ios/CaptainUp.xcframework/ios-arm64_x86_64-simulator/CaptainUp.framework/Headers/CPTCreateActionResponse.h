//
//  CreateActionResponse.h
//  captainup_sdk
//
//  Created by David Azriel on 14/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef CreateActionResponse_h
#define CreateActionResponse_h

#import "CPTResponse.h"
#import "CPTBadgeProgressDictionary.h"
#import "CPTAction.h"
#import "CPTCurrency.h"
#import "CPTBadge.h"
#import "CPTLevel.h"
#import "CPTAvailableReward.h"

/**
 CPTCreateActionResponse object
 */
@protocol CPTCreateActionResponse <CPTResponse>

/**
 The list of the new badges the user achieved
 All the elements of the array conform to the CPTBadge protocol
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTBadge>> *achievedBadges;

/**
 The list of levels the user have been promoted to.
 Can be zero, one or many levels. If the user has advanced more than one level because
 of an action, the levels will be sorted from low to high.
 All the elements of the array conform to the CPTLevel protocol
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTLevel>> *advancedLevels;

/**
 The number of points, in total, the user received from the action and the badges
 */
@property (nonatomic, readonly) CPTPoint awardedPoints;

/**
 The base number of points the user received for the action
 */
@property (nonatomic, readonly) CPTPoint awardedBasePoints;

/**
 The current user's badge progress
 */
@property (nonatomic, readonly, nonnull) CPTBadgeProgressDictionary *badgeProgress;

/**
 The action's data
 */
@property (nonatomic, readonly, nonnull) id<CPTAction> action;

/**
 Currencies received
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id<CPTCurrency>>* currencies;

/**
 Monthly points
 */
@property (nonatomic, readonly) CPTPoint monthlyPoints;

/**
 Weekly points
 */
@property (nonatomic, readonly) CPTPoint weeklyPoints;

/**
 Daily points
 */
@property (nonatomic, readonly) CPTPoint dailyPoints;

/**
 The user's position in all the leaderboards
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,NSNumber*>* leaderboardPositions;

/**
 List of acquired assets ID's
 @return NSArray<NSString*>
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString*> *acquiredAssets;

/**
 Unvailable segmented badges
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString*> *unavailableSegmentedBadges;

/**
 Unvailable segmented assets
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString*> *unavailableSegmentedAssets;

/**
 Available rewards which user can claim.
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTAvailableReward>> *availableRewards;

@end

#endif /* CreateActionResponse_h */
