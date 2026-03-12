//
//  CPTNotificationsQueue.h
//  CaptainUp
//
//  Created by David Azriel on 17/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTNotificationsQueue_h
#define CPTNotificationsQueue_h

#import "CPTObject.h"
#import "CPTNotificationListener.h"

/**
 Manages a user's private notifications, such as the ones received when achieving a new badge or a new level.
 */
@protocol CPTNotificationsQueue <NSObject>

- (void)addListener:(nonnull id<CPTNotificationListener>)listener;

- (void)removeListener:(nonnull id<CPTNotificationListener>)listener;

/**
 Retrieves, but does not remove, the head of the notification's queue,
 or returns <code>null</code> if this queue is empty.
 
 @return the head of this queue, or <code>null</code> if this queue is empty
 */
- (nullable id<CPTObject>)peek;

/**
 Retrieves and removes the notification at the head of this queue,
 or returns <code>null</code> if this queue is empty. The notification is also deleted from the
 captain up servers.
 
 @return the head of this queue, or <code>null</code> if this queue is empty
 */
- (nullable id<CPTObject>)poll;

/**
 Returns the number of notifications in the queue.
 @return the number of notifications in the queue
 */
- (NSUInteger)count;

/**
 Removes all notifications from the queue. The notifications are also removed from the
 Captain Up servers.
 */
- (void)clear;

/**
 Description
 */
@property (nonatomic, readonly) BOOL isEmpty;

@end

#endif /* CPTNotificationsQueue_h */
