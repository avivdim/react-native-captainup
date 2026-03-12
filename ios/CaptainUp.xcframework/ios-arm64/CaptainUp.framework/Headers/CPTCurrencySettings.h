//
//  CPTCurrencySettings.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 7/29/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTCurrencySettings_h
#define CPTCurrencySettings_h

#import "CPTObject.h"

/**
 Description
 */
@protocol CPTCurrencySettings <CPTObject>

/**
 The ID of the Currency Settings
 */
@property (nonatomic, readonly, nonnull) NSString* currencySettingId;

/**
 The name of the currency
 */
@property (nonatomic, readonly, nonnull) NSString* name;

/**
 The currency description
 */
@property (nonatomic, readonly, nonnull) NSString* currencySettingDescription;

/**
 The currency html description,
 use this to add support for style and hyperlinks for example.
 */
@property (nonatomic, readonly, nonnull) NSString* descriptionHtml;

/**
 Currency active state
 */
@property (nonatomic, readonly) BOOL isActive;

/**
 The date that the currency was created
 */
@property (nonatomic, readonly, nullable) NSDate* createdAt;

/**
 The date that the currency was updated
 */
@property (nonatomic, readonly, nullable) NSDate* updatedAt;

/**
 The currency image URL
 */
@property (nonatomic, readonly, nullable) NSString* imageURL;

/**
 The currency custom data
 */
@property (nonatomic, readonly, nonnull) NSDictionary* customData;

@end

#endif /* CPTCurrencySettings_h */
