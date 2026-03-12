//
//  BadgeProgress.h
//  captainup_sdk
//
//  Created by David Azriel on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef BadgeProgress_h
#define BadgeProgress_h

#import "CPTObject.h"
#import "CPTConditionProgress.h"
#import "CPTRewardProgress.h"

/**
 
 */
@protocol CPTBadgeProgress <CPTObject>

/**
 The user’s badge progress, as a number between 0 and 1.
 Completed badges will have `1` as their progress, badges with no progress will have `0`
 as their progress. For example, if the user visited one time, out of a total of
 four required visits, then the progress will be set to 0.25.
 */
@property (nonatomic, readonly) double progress;

/**
 The number of conditions completed
 */
@property (nonatomic, readonly) NSUInteger completedConditionsCount;

/**
 The badge's conditions progress
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id<CPTConditionProgress>> *conditionProgress;

/**
 The number of times the badge was completed
 */
@property (nonatomic, readonly) NSUInteger timesCompleted;

/**
 The latest date the badge was completed on or nil if the badge is not yet completed.
 */
@property (nonatomic, readonly, nullable) NSDate* completedDate;

/**
 The badge's rewards progress
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id<CPTRewardProgress>> *rewardProgress;

@end

#endif /* BadgeProgress_h */
