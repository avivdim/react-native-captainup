//
//  CPTPropertiesUser.h
//  CaptainUp
//
//  Created by Nirav Parmar on 27/12/23.
//  Copyright © 2023 Captain Up. All rights reserved.
//

#ifndef PropertiesUser_h
#define PropertiesUser_h

#import "CPTObject.h"
#import "CPTPropertiesUser.h"
/**
 CPTPropertiesUser
 */
@protocol CPTPropertiesUser <CPTObject>

/**
 The active. Value should be true or false
 */
@property (nonatomic, readonly) Boolean active;

/**
 The URL to the uesr's page or your app, or the user's website.
 */
@property (nonatomic, readonly, nonnull) NSString *url;

/**
 The api key
 */
@property (nonatomic, readonly, nonnull) NSString *apiKey;

/**
 The user's mobile token
 */
@property (nonatomic, readonly, nonnull) NSString *mobileToken;

/**
 The inbox background period. If any value is not provided, by default it will be 600000.
 */
@property (nonatomic, readonly) NSUInteger inboxBackgroundPeriod;

/**
 The user's login action
 */
@property (nonatomic, readonly, nonnull) NSString *loginAction;

/**
 To determine if logs will be visible or not in the console
 */
@property (nonatomic, readonly) Boolean isDebugLogs;


@end

#endif /* IntegrationUser_h */

