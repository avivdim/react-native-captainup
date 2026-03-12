//
//  CPTInbox.h
//  CaptainUp
//
//  Created by David Azriel on 17/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTInbox_h
#define CPTInbox_h

#import "CPTObject.h"
#import "CPTInboxListener.h"
#import "CPTQuery.h"
#import "CPTInboxItem.h"

/**
 * Allows to query and mark as messages as read of the user's inbox.
 */
@protocol CPTInbox <NSObject>

- (void)addListener:(nonnull id<CPTInboxListener>)listener;

- (void)removeListener:(nonnull id<CPTInboxListener>)listener;

/**
 * Retrieves the user's inbox given a query.
 * @param query query parameters. To create a query object use CPTQueryBuilder.
 * @param callback a callback that will contain the response and any exception that might
 *                 have risen during the execution.
 */
- (void)query:(nonnull id<CPTQuery>)query to:(RESPONSE_CALLBACK(NSArray<id <CPTInboxItem>> *))callback;

-(NSInteger)getNewMessageCount;

/**
 * Checks if there are any new unread messages and updates the inbox accordingly.
 * This method check with the Captain Up Servers asynchronously and will notify it is done using
 * a listener.
 * Every subsequent calls to query will be based on these results (meaning, determining which Inbox Item is unread).
 * Do not call this method if you configured the Captain Up Framework to periodically check
 * for Inbox updates. To set up periodic updates,  specify a positive integer value for the key
 * "inbox_update_period" in the Captain Up Configuration file.
 * If you did not configure automatic update of the Inbox, make sure you call this method
 * before calling query.
 */
- (void)checkForNewMessages;

/**
 * Marks all of the user's inbox as read .
 * This method is asynchronous. In case of an error, an error will be raised as an event to the
 * inbox's error listeners.
 */
- (void)markAllAsRead;

/**
 * Marks a selected message of the user's inbox as read .
 * This method is asynchronous. In case of an error, an error will be raised as an event to the
 * inbox's error listeners.
 */
- (void)markMessageAsRead:(nonnull NSString*)messageID;

/**
 Get list of unread inbox messages items
 */
-(nonnull NSArray<id<CPTInboxItem>>*)getUnreadInboxMessages;

/**
 Get list of unread inbox notifications items
 */
-(nonnull NSArray<id<CPTInboxItem>>*)getUnreadInboxNotifications;

@end

#endif /* CPTInbox_h */
