//
//  CPTInboxItem.h
//  CaptainUp
//
//  Created by David Azriel on 17/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTInboxItem_h
#define CPTInboxItem_h

#import "CPTObject.h"
#import "CPTCurrency.h"

/**
 Describes a Captain Up Inbox item.
 The item may or may not have any content (the actual message) and may or may not award or subtract
 points from the user.
 */
@protocol CPTInboxItem <CPTObject>

/**
 The item's message.
 @return the item's message. May be <code>null</code>.
 */
@property (nonatomic, readonly, nonnull) NSString *content;

/**
 The items' message in HTML format.
 @return the items' message in HTML format. May be <code>null</code>
 */
@property (nonatomic, readonly, nonnull) NSString *contentHTML;

/**
 The time at which the message was sent.
 @return the time the message was sent.
 */
@property (nonatomic, readonly, nonnull) NSDate *timestamp;

/**
 The currencies awarded (or reduced) from the user as part of the message. In most cases, the
 messages does not change the user's currencies balance, and this will return <code>0</code> for each currency.
 @return the currencies awarded (or reduced) from the user as part of the message.
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id<CPTCurrency>> *currencies;

/**
 Was this message read before or not.
 @return <code>true</code> if the message was never marked as read before,
         <code>false</code> otherwise.
 @see markAllAsRead
 */
@property (nonatomic, readonly) BOOL isUnread;

/**
 Get the message title
 @return he message title
 */
@property (nonatomic, readonly, nonnull) NSString *title;

/**
 Get the message short description text.
 @return short content
 */
@property (nonatomic, readonly, nonnull) NSString *shortContent;

-(nonnull NSString*)getID;

/**
 get message difficulty
 */
@property (nonatomic, readonly) NSUInteger difficulty;

/**
 get preset image
 */
@property (nonatomic, readonly, nonnull) NSString* presetImage;

/**
 is this as notificaion or  message
 */
@property (nonatomic, readonly) BOOL isNotification;

/**
 Get the message custom data
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString*, id>* customData;

@end

#endif /* CPTInboxItem_h */
