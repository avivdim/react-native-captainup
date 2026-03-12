//
//  CPTNotificationListener.h
//  CaptainUp
//
//  Created by David Azriel on 17/07/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTNotificationListener_h
#define CPTNotificationListener_h

/**
 CPTNotificationListener
 */
@protocol CPTNotificationListener <NSObject>

@optional
/**
 Triggers once notification added
 */
- (void)onNotificationsAdded;

@end

#endif /* CPTNotificationListener_h */
