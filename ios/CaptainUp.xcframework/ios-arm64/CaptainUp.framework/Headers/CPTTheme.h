//
//  Theme.h
//  captainup_sdk
//
//  Created by David Azriel on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef Theme_h
#define Theme_h

#import <UIKit/UIKit.h>
#import "CPTObject.h"

/**
 Description
 */
@protocol CPTTheme <CPTObject>

/**
 The theme's name
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 The primary theme's color.
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *primaryColor;

/**
 A dark shade of the primary theme color.
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *primaryColorDark;

/**
 A light shade of the primary theme color.
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *primaryColorLight;

/**
 The secondary theme color.
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *secondaryColor;

/**
 A light shade of the secondary theme color.
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *secondaryColorDark;

/**
 A light shade of the secondary theme color.
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *secondaryColorLight;

/**
 A shade of grey for the theme design
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *greyColor;

/**
 A shade of white for the theme design.
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *whiteColor;

/**
 A shade of black for the theme design.
 If no color was defined in the theme, will return nil.
 */
@property (nonatomic, readonly, nonnull) UIColor *blackColor;

@end

#endif /* Theme_h */
