//
//  GameCenter.h
//  captainup_sdk
//
//  Created by David Azriel on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef GameCenter_h
#define GameCenter_h

#import "CPTObject.h"

/**
 CPTGameCenter
 */
@protocol CPTGameCenter <CPTObject>

/**
 The title of the app's game center.
 */
@property (nonatomic, readonly, nonnull) NSString *introTitle;

/**
 The text for the app's game center.
 */
@property (nonatomic, readonly, nonnull) NSString *introText;

/**
 The HTML text of the app's game center.
 */
@property (nonatomic, readonly, nonnull) NSString *introTextHTML;

@end

#endif /* GameCenter_h */
