//
//  IntegrationUser.h
//  captainup_sdk
//
//  Created by David Azriel on 09/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef IntegrationUser_h
#define IntegrationUser_h

#import "CPTObject.h"

/**
 CPTIntegrationUser
 */
@protocol CPTIntegrationUser <CPTObject>

/**
 Required. Your own unique ID for the user.
 */
@property (nonatomic, readonly, nonnull) NSString *userId;

/**
 The user's full name.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 The user's display name.
 */
@property (nonatomic, readonly, nonnull) NSString *displayName;

/**
 The user's first name.
 */
@property (nonatomic, readonly, nonnull) NSString *firstName;

/**
 The user's last name.
 */
@property (nonatomic, readonly, nonnull) NSString *lastName;

/**
 A full URL to the user's profile image.
 */
@property (nonatomic, readonly, nonnull) NSString *imageURL;

/**
 The user's email address.
 */
@property (nonatomic, readonly, nonnull) NSString *email;

/**
 The URL to the uesr's page or your app, or the user's website.
 */
@property (nonatomic, readonly, nonnull) NSString *url;

/**
 You can add any other field that you want to the user data, provided it’s not a nested field,
 and that it contains a <code>boolean</code>, <code>String</code>
 or numeric value. You can use this data later to segment your users, create badge conditions
 or see reports and analyze your actions and users.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString*,id> *customData;

@end

#endif /* IntegrationUser_h */
