//
//  CPTAcquiredAsset.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 5/25/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTAcquiredAsset_h
#define CPTAcquiredAsset_h

#import "CPTObject.h"

/**
 AcquiredAsset is how you can track a player's progress on an asset.
 */
@protocol CPTAcquiredAsset <CPTObject>

/**
 The ID of the asset
 */
@property (nonatomic, readonly, nonnull) NSString* assetId;

/**
 amount
 */
@property (nonatomic, readonly) NSUInteger amount;

/**
 last acquired date
 */
@property (nonatomic, readonly, nonnull) NSDate* lastAcquired;

@end

#endif /* CPTAcquiredAsset_h */
