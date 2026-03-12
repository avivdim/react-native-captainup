//
//  CPTUserListener.h
//  CaptainUp
//
//  Created by David Azriel on 13/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTUserListener_h
#define CPTUserListener_h

#import "CPTObject.h"
#import "CPTUser.h"
#import "CPTBadgeProgressDictionary.h"
#import "CPTCurrency.h"
#import "CPTBadge.h"
#import "CPTLevel.h"


/**
 Use this protocol to listen to events that happen on an ActionableUser.
 This protocol shouold never be implemented on its own. Instead, implement its child protocols
 for each concrete event type you want to listen to.
 */
@protocol CPTUserListener <NSObject>

@optional
/**
 called when user archive badges

 @param user CPTUser object
 @param badges NSArray<id<CPTBadge>> badges array
 */
- (void)onUser:(nonnull id<CPTUser>)user achievedBadges:(nonnull NSArray<id<CPTBadge>> *)badges;

@optional
/**
 called when user archive levels

 @param user CPTUser object
 @param levels NSArray<id<CPTLevel>> levels array
 */
- (void)onUser:(nonnull id<CPTUser>)user achievedLevels:(nonnull NSArray<id<CPTLevel>> *)levels;

@optional
/**
 called when user archive levels

 @param user CPTUser object
 @param map CPTBadgeProgressDictionary Dictionary
 */
- (void)onUser:(nonnull id<CPTUser>)user badgeProgress:(nonnull CPTBadgeProgressDictionary *)map;

@optional
/**
 called when user archive currency

 @param user CPTUser object
 @param currency CPTCurrency object
 @param amount Integer of amount
 */
- (void)onUser:(nonnull id<CPTUser>)user gotCurrency:(nonnull id<CPTCurrency>)currency ofAmount:(NSInteger)amount;

@optional
/**
 called when user leaderboard postiion changed

 @param user CPTUser user
 @param leaderboards NSDictionary<NSString*,NSNumber*> user leaderboard position
 */
- (void)onUser:(nonnull id<CPTUser>)user leaderboardPositionChanged:(nonnull NSDictionary<NSString*,NSNumber*>*)leaderboards;

@optional
/**
 called when user acquire asset

 @param user CPTUser object
 @param asset CPTAcquiredAsset object
 */
- (void)onUser:(nonnull id<CPTUser>)user acquiredAsset:(nonnull id<CPTAcquiredAsset>)asset;

@optional
/**
 called when user acheive trophy

 @param user CPTUser object
 @param asset CPTAcquiredAsset object
 */
- (void)onUser:(nonnull id<CPTUser>)user achievedTrophy:(nonnull id<CPTAcquiredAsset>)asset;

@optional
/**
  called when user acquire shop item

 @param user CPTUser object
 @param asset CPTAcquiredAsset object
 */
- (void)onUser:(nonnull id<CPTUser>)user acquiredShopItem:(nonnull id<CPTAcquiredAsset>)asset;

/**
 called when new rewadr is available for claim

 @param user CPTUser object
 @param reward CPTReward object
 */
- (void)onUser:(nonnull id<CPTUser>)user newRewardAvailableForClaim:(nonnull id<CPTReward>)reward withBadge:(nonnull id<CPTBadge>) badge;

@optional
/**
 called when user action processed

 @param user CPTUser object
 @param action CPTAction object
 */
- (void)onUser:(nonnull id<CPTUser>)user actionProcessed:(nonnull id<CPTAction>)action;

@optional
/**
 called when error occured in any operation

 @param user CPTUser object
 @param error NSError object
 */
- (void)onUser:(nonnull id<CPTUser>)user error:(nullable NSError *)error;

@end

#endif /* CPTUserListener_h */
