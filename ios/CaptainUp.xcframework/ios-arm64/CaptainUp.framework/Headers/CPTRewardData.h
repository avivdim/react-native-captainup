//
//  CPTRewardData.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 5/4/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTRewardData_h
#define CPTRewardData_h

#import "CPTObject.h"

/**
 Reward data object, is used to store custom data field on an reward object.
 */
@protocol CPTRewardData <CPTObject>

/**
 Reward data id
 */
@property (nonatomic, readonly, nonnull) NSString* rewardDataId;

/**
 Reward data name
 */
@property (nonatomic, readonly, nonnull) NSString* name;

/**
 reward data value
 */
@property (nonatomic, readonly, nonnull) id value;

@end

#endif /* CPTRewardData_h */
