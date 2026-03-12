//
//  CPTSocketNotificationListener.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 3/9/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#import "CPTCreateActionResponse.h"

#ifndef CPTSocketNotificationListener_h
#define CPTSocketNotificationListener_h

/**
 Soclet notification listner
 */
@protocol CPTSocketNotificationListener <NSObject>

@optional
/**
 Action Response arrived

 @param response action response with updated infomration
 */
- (void)onActionResponse:(nonnull id<CPTCreateActionResponse>)response;


@end

#endif /* CPTSoclketNotificationListener_h */
