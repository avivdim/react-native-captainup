//
//  IntegrationUserBuilder.h
//  captainup_sdk
//
//  Created by David Azriel on 09/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef IntegrationUserBuilder_h
#define IntegrationUserBuilder_h

#import "CPTIntegrationUser.h"

/**
 CPTIntegrationUserBuilder
 */
@interface CPTIntegrationUserBuilder : NSObject

/**
 CPTIntegrationUserBuilder Initializer

 @param builderBlock builderBlock description
 @return return CPTIntegrationUser new object
 */
+ (nonnull id<CPTIntegrationUser>)build:( nonnull void(^)( CPTIntegrationUserBuilder *_Nonnull builder))builderBlock;

/**
 Required. Your own unique ID for the user.
 */
@property (nonatomic, nonnull) NSString *userId;

/**
 The user's full name.
 */
@property (nonatomic, nonnull) NSString *name;

/**
 The user's display name.
 */
@property (nonatomic, nonnull) NSString *displayName;

/**
 The user's first name.
 */
@property (nonatomic, nonnull) NSString *firstName;

/**
 The user's last name.
 */
@property (nonatomic, nonnull) NSString *lastName;

/**
 A full URL to the user's profile image.
 */
@property (nonatomic, nonnull) NSString *imageURL;

/**
 The user's email address.
 */
@property (nonatomic, nonnull) NSString *email;

/**
 The URL to the uesr's page or your app, or the user's website.
 */
@property (nonatomic, nonnull) NSString *url;

/**
 You can add any other field that you want to the user data, provided it’s not a nested field,
 and that it contains a <code>boolean</code>, <code>String</code>
 or numeric value. You can use this data later to segment your users, create badge conditions
 or see reports and analyze your actions and users.
 */
@property (nonatomic, readonly, nullable) NSMutableDictionary *customData;

/**
 Sets a signature for the integration user. The signature should be calculated using
 the app's secret key (not the mobile token) as explained here:
 https://captainup.com/help/javascript/user-integration#toc-secure-user-integration .
 The signature is not verified on the client side, and is sent as-is to Captain Up.
 */
@property (nonatomic, nonnull) NSString *signature;

@end

#endif /* IntegrationUserBuilder_h */
