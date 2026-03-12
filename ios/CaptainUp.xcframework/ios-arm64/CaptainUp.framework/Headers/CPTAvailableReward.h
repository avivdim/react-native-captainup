//
//  CPTAvailableReward.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 12/26/18.
//  Copyright © 2018 Captain Up. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef CPTAvailableReward_h
#define CPTAvailableReward_h

#import "CPTObject.h"

/**
 Available Reward for user to claim
 */
@protocol CPTAvailableReward <CPTObject>

/**
  Reward id
 */
@property (nonatomic, readonly, nonnull) NSString* rewardId;

/**
 List of times when reward was awarded and not yet claimed. As sooon as the reward was claimed respective time entry would be removed.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSDate*>* timestamps;

@end

#endif /* CPTAvailableReward_h */
