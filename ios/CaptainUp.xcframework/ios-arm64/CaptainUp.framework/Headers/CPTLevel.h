//
//  Level.h
//  captainup_sdk
//
//  Created by David Azriel on 02/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef Level_h
#define Level_h

#import "CPTObject.h"
#import "CPTImageFiles.h"

/**
 Description
 */
@protocol CPTLevel <CPTObject>

/**
 The ID of the level
 */
@property (nonatomic, readonly, nonnull) NSString* levelId;

/**
 The name of the level
 */
@property (nonatomic, readonly, nonnull) NSString* name;

/**
 The level description
 */
@property (nonatomic, readonly, nonnull) NSString* levelDescription;

/**
 The level ordinal number
 */
@property (nonatomic, readonly) NSUInteger ordinalNumber;

/**
 The number of points needed to reach this level
 */
@property (nonatomic, readonly) CPTPoint points;

/**
 The level's custom data.
 A dictionary between the key (always NSString) to the data (NSString, NSNumber or NSArray)
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString*,id> *customData;

/**
 The level preset image path
 */
@property (nonatomic, readonly, nonnull) NSString* imageURL;

/**
 The level image files
 */
@property (nonatomic, readonly, nonnull) id<CPTImageFiles> imageFiles;

@end

#endif /* Level_h */
