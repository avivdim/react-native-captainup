//
//  Badge.h
//  captainup_sdk
//
//  Created by David Azriel on 02/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef Badge_h
#define Badge_h

#import "CPTCondition.h"
#import "CPTReward.h"
#import "CPTImageFiles.h"

@protocol CPTUser;

/**
 
 */
@protocol CPTBadge <CPTObject,NSCopying>

/**
 The badge ID
 */
@property (nonatomic, readonly, nonnull) NSString *badgeId;

/**
 Whether the badge is active or not (in v1 - this will always be true)
 */
@property (nonatomic, readonly) BOOL isActive;

/**
 The name of the badge
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 The badge description
 */
@property (nonatomic, readonly, nonnull) NSString *badgeDescription;

/**
 Whether the badge is "hidden".
 Hidden badges are to be show as a secret badge in the UI.
 */
@property (nonatomic, readonly) BOOL isHidden;

/**
 A badge that is not visible will be hidden from users that have not achieved it.
 @return true if badge is visible
 */
@property (nonatomic, readonly) BOOL isVisible;

/**
 The number of points that will be awarded to the user for achieving this badge
 */
@property (nonatomic, readonly, getter = getPoints) CPTPoint points;

/**
 The badge weight affect the weight given to each badge when
 we sort, display and recommend the badges to users. The higher
 the weight, the more difficult the badge is considered the be,
 the lower the likelihood we recommend users to complete this badge.
 */
@property (nonatomic, readonly) NSInteger weight;

/**
 The badge's custom data.
 A dictionary between the key (always NSString) to the data (NSString, NSNumber or NSArray)
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString*,id> *customData;

/**
 A URL pointing to the badge's image.
 */
@property (nonatomic, readonly, nonnull) NSString *imageURL;

/**
 Details on the badge's image files
 @return the details of the badge's image files
 */
@property (nonatomic, readonly, nullable) id<CPTImageFiles> imageFiles;

/**
 A list of all the badge conditions for achievment
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTCondition>> *conditions;

/**
 A list of rewards
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTReward>> *rewards;

/**
 A repeatable badge is a badge that can be achieved multiple times.
 you can check inside a player's badge progress to know how many times he achieved a badge
 For example: {@code CaptainUp.getLoggedInUser().getBadgeProgress().get(badge.getID()).getTimesCompleted()}
 
 @return true if a badge is repeatable, false otherwise.
 */
@property (nonatomic, readonly) BOOL repeatable;

/**
 if Badge object has any Reward

 @return return is badge have reward or not
 */
-(BOOL)hasReward;

/**
 Get the currencies awarded when achieving this badge.
 For example: badge.getCurrencies().get("points") will return the amount of points
 awarded when completing the badge's conditions
 
 @return A map where key is the currency name and value is the awarded currency amount
 */
@property (nonatomic ,readonly, nonnull) NSDictionary<NSString*,NSNumber*> *currencies;

/**
 Get badge reward

 @return return CPTRward object or null if badge do not have any reward
 */
-(nullable id<CPTReward>)getReward;

/**
 Segmented badges can be used to  filter the badge presentation according to different user attributes.
 For example - you can add a "market" filter so only users in this specific market can see the badge.
 
 If a badge is segmented, you can check if it is restricted for the current user by checking his unavailable segmented badges list ({@link User#getUnavailableSegmentedBadgesIDs()} -
 A badge that is both segmented and appears in the user restricted segmented badges list should not be shown to that user.
 
 @return true if badge is segmented, false otherwise.
 */
@property (nonatomic, readonly) BOOL isSegmented;

/**
Whether the badge is scheduled or not
*/
@property (nonatomic, readonly) BOOL isScheduled;

/**
Date when the badge will be activated, if badge is scheduled
*/
@property (nonatomic, readonly, nullable) NSDate* activeFromDate;

/**
Date when the badge will be disabled, if badge is scheduled
*/
@property (nonatomic, readonly, nullable) NSDate* disabledFromDate;

/**
 Use this function to know if a badge should be displayed for your specific user
 For example: badge.isSegmentedForUser(CaptainUp.getLoggedInUser())

 @param user CPTUser object
 @return return Bool is segmemted for user or not
 */
-(BOOL)isSegmentedForUser:(nonnull id<CPTUser>)user;

@end

#endif /* Badge_h */
