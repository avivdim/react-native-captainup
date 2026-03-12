//
//  CPTRewardType.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 4/30/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef CPTRewardType_h
#define CPTRewardType_h

#import "CPTObject.h"
#import "CPTRewardTypeProperty.h"

/**
 Description
 */
@protocol CPTRewardType <CPTObject>

/**
 The ID of the reward type
 */
@property (nonatomic, readonly, nonnull) NSString* rewardTypeId;

/**
 Rewrd type name
 */
@property (nonatomic, readonly, nonnull) NSString* name;

/**
 Rewrd type description
 */
@property (nonatomic, readonly, nonnull) NSString* rewardTypeDescription;

/**
 is reward type active
 */
@property (nonatomic, readonly) Boolean isActive;

/**
 image url of reward
 */
@property (nonatomic, readonly, nonnull) NSString* imageURL;

/**
 reward type properties
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTRewardTypeProperty>>* properties;

@end

#endif /* CPTRewardType_h */
