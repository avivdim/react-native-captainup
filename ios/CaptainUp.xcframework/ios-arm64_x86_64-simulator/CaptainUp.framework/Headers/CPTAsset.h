//
//  CPTAsset.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 5/25/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTAsset_h
#define CPTAsset_h

#import "CPTObject.h"
#import "CPTAssetType.h"
#import "CPTImageFiles.h"
#import "CPTReward.h"

@protocol CPTUser;

/**
 An asset object, can be used as a Shop Item {@see getType()}, to track a player's progress on
 an asset check the corresponding AcquiredAsset object that is stored in the player object
 */
@protocol CPTAsset <CPTObject>

/**
 The ID of the asset
 */
@property (nonatomic, readonly, nonnull) NSString* assetId;

/**
 asset type
 */
@property (nonatomic, readonly) CPTAssetType type;

/**
 asset name
 */
@property (nonatomic, readonly, nonnull) NSString* name;

/**
 asset description
 */
@property (nonatomic, readonly, nonnull) NSString* assetDescription;

/**
 is asset active
 */
@property (nonatomic, readonly) BOOL isActive;

/**
 asset acquired on list
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString*>* acquireOn;

/**
 asset weight
 */
@property (nonatomic, readonly) NSUInteger weight;

/**
 asset stock
 */
@property (nonatomic, readonly) NSUInteger stock;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSString* presetImage;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSDate* createdAt;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSDate* updatedAt;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSString* descriptionHtml;

/**
 Description
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,NSNumber*> *currencies;

/**
 Description
 */
@property (nonatomic, readonly, nullable) id<CPTImageFiles> imageFiles;

/**
 Description
 */
@property (nonatomic, readonly) BOOL isUnlimitedStock;

/**
 Asset segmentation allows you to filter the asset presentation according to different user attributes.
 For example - you can add a "market" filter so only users in this specific market can see the asset.
 */
@property (nonatomic, readonly) BOOL isSegmented;

/**
 The Asset Rewards Array
 @return a <code> NSArray<CPTReward> </code> NSArray or Null if there is no reward for this asset
 */
@property (nonatomic, readonly, nullable) NSArray<id<CPTReward>> *rewards;

/**
 The Asset Reward Object

 @return a <code>CPTReward</code> Object or Null if there is no reward for this asset
 */
-(nullable id<CPTReward>)getReward;

/**
 Does the asset has a reward object attached to it

 @return a <code>BOOL</code> true if the asset has a reward object or false if reward object is null
 */
-(BOOL)hasReward;

/**
 Use this function to know if a asset should be displayed for your specific user
 For example: asset.isSegmentedForUser(CaptainUp.getLoggedInUser())

 @param user user object
 @return true if the asset is segmented to the provided user, false otherwise.
 */
-(BOOL)isSegmentedForUser:(nonnull id<CPTUser>)user;

@end


#endif /* CPTAsset_h */
