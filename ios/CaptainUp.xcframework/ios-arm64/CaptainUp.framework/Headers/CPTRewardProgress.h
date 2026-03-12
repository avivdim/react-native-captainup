//
//  RewardProgress.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 1/30/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef RewardProgress_h
#define RewardProgress_h

#import "CPTObject.h"

/**
 Description
 */
@protocol CPTRewardProgress <CPTObject>

//  Indicates the claim status of a reward - the amount of times the user claimed the reward
//  claimed status (0 - not yet claimed, 1 - claimed)
@property (nonatomic, readonly) NSInteger claimed;


-(bool)isClaimed;

@end

#endif /* RewardProgress_h */
