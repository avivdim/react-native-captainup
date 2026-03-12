//
//  CPTSocialFeedResponse.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 4/18/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTSocialFeedResponse_h
#define CPTSocialFeedResponse_h

#import "CPTSocialFeedItem.h"
#import "CPTResponse.h"

/**
 social feed response
 */
@protocol CPTSocialFeedResponse <CPTResponse>

/**
 social feed item list
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTSocialFeedItem>> *items;

@end

#endif /* CPTSocialFeedResponse_h */
