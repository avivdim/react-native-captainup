//
//  BadgeProgressDictionary.h
//  captainup_sdk
//
//  Created by David Azriel on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef BadgeProgressDictionary_h
#define BadgeProgressDictionary_h

#import "CPTObject.h"
#import "CPTBadgeProgress.h"

/**
 
 */
@interface CPTBadgeProgressDictionary : NSDictionary<NSString*,id<CPTBadgeProgress>> <CPTObject>

/**
 last updated badge
 */
@property (nonatomic, readonly, nonnull) NSDate *lastUpdateDate;

/**
 Initialize

 @param source Badge Progress source Dictionary
 @param dic dic Badge Progress Dictionary
 @param lastUpdated badge progress last updated data
 @return return Dictionary of badge progress
 */
- (nonnull instancetype)initWithSourceDictionary:(nonnull NSDictionary<NSString*, id> *)source badgeProgressDictionary:(nonnull NSMutableDictionary<NSString*,id <CPTBadgeProgress>> *)dic andDate:(nonnull NSDate *)lastUpdated;

/**
 Check equality of CPTBadgeProgressDictionary

 @param other other CPTBadgeProgressDictionary object
 @return return Bool true of both object are equal
 */
- (BOOL)isEqualToBadgeProgressDictionary:(nonnull CPTBadgeProgressDictionary *)other;

/**
 Find completed badges

 @return return CPTBadgeProgressDictionary badge progress Dictionary of completed badges
 */
- (nonnull CPTBadgeProgressDictionary *)findCompletedBadges;

/**
 Find Incomplete badges

 @return return CPTBadgeProgressDictionary badge progress Dictionary of Incomplete badges
 */
- (nonnull CPTBadgeProgressDictionary *)findIncompleteBadges;

/**
 Find object of bage id

 @param aKey aKey Badge id
 @return return CPTBadgeProgress badge progress object or null of no badge found
 */
- (nullable id<CPTBadgeProgress>)objectForKey:(nullable NSString*)aKey;

/**
 Set object of bage id

 @param anObject CPTBadgeProgress bage progress with badge id
 @param aKey NSString bage id
 */
- (void)setObject:(nonnull id<CPTBadgeProgress>)anObject forKey:(nonnull NSString*)aKey;

@end

#endif /* BadgeProgressDictionary_h */
