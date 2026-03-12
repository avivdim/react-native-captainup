//
//  AcquiredAssetClass.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 5/25/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPTAcquiredAsset.h"

@interface CPTAcquiredAsset : NSObject <CPTAcquiredAsset>

- (BOOL)isEqualToAcquiredAsset:(CPTAcquiredAsset*)other;

-(instancetype) initWithAssetId:(NSString*)asssetID_ andAmount:(NSUInteger) amount_ andLastAcquired:(NSDate*)lastAcquired_;

@end
