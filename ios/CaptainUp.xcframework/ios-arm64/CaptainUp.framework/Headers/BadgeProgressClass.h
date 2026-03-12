//
//  BadgeProgressClass.h
//  captainup_sdk
//
//  Created by David Azriel on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef BadgeProgressClass_h
#define BadgeProgressClass_h

#import "CPTBadgeProgress.h"

@interface CPTBadgeProgress : NSObject <CPTBadgeProgress>

- (instancetype) initWithBadgeProgress:(id<CPTBadgeProgress>)badgeProgress completedDate:(NSDate *)completedDate;
- (BOOL)isEqualToBadgeProgress:(CPTBadgeProgress*)other;

-(instancetype) initWithProgress:(double)progress_ andCompletedComditionCount:(NSUInteger) completedConditionsCount_ andConditionProgress:(NSDictionary<NSString*,id<CPTConditionProgress>>*) conditionProgress_ andTimesCompleted:(NSUInteger) timesCompleted_ andCompletedDate:(NSDate*)completedDate_ andRewardProgress:(NSDictionary<NSString*,id<CPTRewardProgress>> *)rewardProgress_;

@end

#endif /* BadgeProgressClass_h */
