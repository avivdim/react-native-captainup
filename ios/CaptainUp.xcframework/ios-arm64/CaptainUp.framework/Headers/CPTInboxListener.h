//
//  CPTInboxListener.h
//  CaptainUp
//
//  Created by David Azriel on 17/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTInboxListener_h
#define CPTInboxListener_h

#import "CPTInboxItem.h"

/**
 CPTInboxListener
 */
@protocol CPTInboxListener <NSObject>

@optional
/**
 Triggers on inbox error

 @param error NSError error object
 */
- (void)onInboxError:(nullable NSError *)error;

@optional
/**
 Triggers on new message

 @param items NSArray<id<CPTInboxItem>>*  List of CPTInboxItem object
 */
- (void)onNewInboxMessages:(nonnull NSArray<id<CPTInboxItem>>*) items;

@optional
/**
 Triggers on new Inbox notification

 @param items NSArray<id<CPTInboxItem>>* List of CPTInboxItem object
 */
- (void)onNewInboxNotification:(nonnull NSArray<id<CPTInboxItem>>*) items;

@end

#endif /* CPTInboxListener_h */
