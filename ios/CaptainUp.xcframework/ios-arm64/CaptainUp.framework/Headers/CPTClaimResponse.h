//
//  CPTClaimResponse.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 2/1/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTClaimResponse_h
#define CPTClaimResponse_h

#import "CPTResponse.h"
#import "CPTUser.h"
#import "CPTReward.h"

/**
 Claim response object
 */
@protocol CPTClaimResponse <CPTResponse>

/**
 Reward
 */
@property (nonatomic, readonly, nonnull) id<CPTReward> reward;

/**
 Available rewards which user can claim.
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTAvailableReward>> *availableRewards;

@end



#endif /* CPTClaimResponse_h */
