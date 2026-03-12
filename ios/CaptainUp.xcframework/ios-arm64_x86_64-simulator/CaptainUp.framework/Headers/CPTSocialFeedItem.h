//
//  CPTSocialFeedItem.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 4/18/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTSocialFeedItem_h
#define CPTSocialFeedItem_h

#import "CPTAction.h"
#import "CPTUser.h"

/**
 Description
 */
@protocol CPTSocialFeedItem <CPTAction>

/**
 get user

 @return return CPTUser user objecet
 */
-(nonnull id<CPTUser>)getUser;

/**
 action title
 */
@property(nonnull, nonatomic, readonly) NSString *actionTitle;

@end

#endif /* CPTSocialFeedItem_h */
