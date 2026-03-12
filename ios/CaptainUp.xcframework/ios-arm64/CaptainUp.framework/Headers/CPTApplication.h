//
//  Application.h
//  captainup_sdk
//
//  Created by David Azriel on 09/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef Application_h
#define Application_h

#import "CPTObject.h"
#import "CPTGameCenter.h"
#import "CPTTheme.h"
#import "CPTBadge.h"
#import "CPTActionSettings.h"
#import "CPTLevel.h"
#import "CPTRewardType.h"
#import "CPTAsset.h"
#import "CPTAssetType.h"
#import "CPTCurrencySettings.h"

/**
 An app holds the information about the Captain Up experience in your site or app.
 The app resource holds all the settings and configurations related to your app,
 including information about the app's actions and levels
 */
@protocol CPTApplication <CPTObject>

/**
 The ID of the app.
 @return the ID of the app.
 */
@property (nonatomic, readonly, nonnull) NSString *appId;

/**
 The URL to your app's logo. Will default to a community logo.
 @return the URL to the app's logo.
 */
@property (nonatomic, readonly, nonnull) NSString *logoURL;

/**
 The name of the app.
 @return the name of the app.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 The URL of the application.
 @return the URL of the application.
 */
@property (nonatomic, readonly, nonnull) NSString *applicationURL;

/**
 The details of the app's game center display (like the title and text).
 @return the app's game center's details.
 */
@property (nonatomic, readonly, nonnull) id<CPTGameCenter> gameCenterDetails;

/**
 The details of the theme defined for the app.
 @return the app's theme.
 */
@property (nonatomic, readonly, nonnull) id<CPTTheme> theme;

/**
 A map of all the application badges by their Badge ID.
 @return a map of all the application badges by their Badge ID (NSString).
         The value conforms to the CPTBadge protocol.
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id<CPTBadge>> *badges;

/**
 The app's action's settings.
 @return the app's action's settings.
          Each element in the array conforms to the CPTActionSettings protocol.
 */
@property (nonatomic, readonly, nonnull) NSArray<id <CPTActionSettings>> *actionSettings;

/**
 List of the app's levels
 @return list of the app's levels.
          Each element in the array conforms to the CPTLevel protocol.
 */
@property (nonatomic, readonly, nonnull) NSArray<id <CPTLevel>> *levels;

/**
  App currency ratio (default is 1)
 */
@property (nonatomic, readonly) NSUInteger ratio;

/**
  map of the app's reward types
  @return map of the app's reward types by their reward type id
          The value conforms to the CPTRewardType protocol.
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id <CPTRewardType>> *rewardTypes;

/**
  A map of all the application assets by their {@link Asset#getID() Asset Type ID}.
  @return a map of all the application assets types by their {@link Asset#getID() Asset ID}.
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id<CPTAsset>> *assets;

/**
 A map of application assets by asset type

 @param type CPTAssetType
 @return a map of all the application assets of a type
 */
-(nonnull NSDictionary<NSString*,id<CPTAsset>>*)getAssetsByType:(CPTAssetType)type;

/**
the app Currency Settings Map. where key is currency name and value is CPTCurrencySettings object.
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id<CPTCurrencySettings>>* currencySettings;

@end

#endif /* Application_h */
