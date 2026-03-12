//
//  PropertiesUserBuilder.h
//  CaptainUp
//
//  Created by Nirav Parmar on 27/12/23.
//  Copyright © 2023 Captain Up. All rights reserved.
//

#ifndef PropertiesUserBuilder_h
#define PropertiesUserBuilder_h

#import "CPTPropertiesUser.h"

/**
 CPTPropertiesUserBuilder
 */
@interface CPTPropertiesUserBuilder : NSObject

/**
 CPTPropertiesUserBuilder Initializer

 @param builderBlock builderBlock description
 @return return CPTPropertiesUser new object
 */
+ (nonnull id<CPTPropertiesUser>)build:( nonnull void(^)( CPTPropertiesUserBuilder *_Nonnull builder))builderBlock;

/**
 The active. Value should be true or false
 */
@property (nonatomic) Boolean active;

/**
 The URL to the uesr's page or your app, or the user's website.
 */
@property (nonatomic, nonnull) NSString *url;

/**
 The api key
 */
@property (nonatomic, nonnull) NSString *apiKey;

/**
 The user's mobile token.
 */
@property (nonatomic, nonnull) NSString *mobileToken;

/**
 The inbox background period. If any value is not provided, by default it will be 600000.
 */
@property (nonatomic) NSUInteger inboxBackgroundPeriod;

/**
 The user's login action
 */
@property (nonatomic, nonnull) NSString *loginAction;

/**
 To determine if logs will be visible or not in the console
 */
@property (nonatomic) Boolean isDebugLogs;

/**
 You can add any other field that you want to the user data, provided it’s not a nested field,
 and that it contains a <code>boolean</code>, <code>String</code>
 or numeric value. You can use this data later to segment your users, create badge conditions
 or see reports and analyze your actions and users.
 */

@property (nonatomic, readonly , nullable) NSMutableDictionary *customData;

/**
 Sets a signature for the integration user. The signature should be calculated using
 the app's secret key (not the mobile token) as explained here:
 https://captainup.com/help/javascript/user-integration#toc-secure-user-integration .
 The signature is not verified on the client side, and is sent as-is to Captain Up.
 */

@property (nonatomic, nonnull) NSString *signature;

@end

#endif /* IntegrationUserBuilder_h */
