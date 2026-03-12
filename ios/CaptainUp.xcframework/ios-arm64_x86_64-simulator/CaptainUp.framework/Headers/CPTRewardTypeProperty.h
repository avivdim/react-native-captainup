//
//  CPTRewardTypeProperty.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 5/9/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTRewardTypeProperty_h
#define CPTRewardTypeProperty_h

#import "CPTObject.h"

/**
 Description
 */
@protocol CPTRewardTypeProperty <CPTObject>

/**
 Reward type property id
 */
@property (nonatomic, readonly, nonnull) NSString* rewardTypePropertyId;

/**
 Reward type property name
 */
@property (nonatomic, readonly, nonnull) NSString* name;

/**
 reward type property type
 */
@property (nonatomic, readonly, nonnull) NSString* type;

@end

#endif /* CPTRewardTypeProperty_h */
