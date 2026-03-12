//
//  CPTListener.h
//  CaptainUp
//
//  Created by David Azriel on 13/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTListener_h
#define CPTListener_h

#import "CPTActionableUser.h"
#import "CPTApplication.h"

/**
 Listener for the operations of the Captain Up Facade class.
 This protocol should never be implemented on its own. Instead, implement its child interfaces.
 for each concrete event type you wish to listen to.
 */
@protocol CPTListener <NSObject>

@optional
/**
 Triggers once application is connected to sever

 @param application CPTApplication application object
 */
- (void)onAfterConnect:(nonnull id<CPTApplication>)application;

@optional
/**
 Triggers once user authenticated successfully

 @param user CPTActionableUser user object
 */
- (void)onAuthenticationDone:(nonnull id<CPTActionableUser>)user;

@optional
/**
 Triggers if any error encounter during connection of authntication

 @param error NSError error object
 */
- (void)onError:(nullable NSError *)error;

@end

#endif /* CPTListener_h */
