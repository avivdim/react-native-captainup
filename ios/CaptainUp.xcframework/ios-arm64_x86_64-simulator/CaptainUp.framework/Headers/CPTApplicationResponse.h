//
//  ApplicationResponse.h
//  captainup_sdk
//
//  Created by David Azriel on 09/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ApplicationResponse_h
#define ApplicationResponse_h

#import "CPTResponse.h"
#import "CPTApplication.h"

/**
 Description
 */
@protocol CPTApplicationResponse <CPTResponse>

/**
 The requested application's information.
 */
@property (nonatomic, readonly, nonnull) id<CPTApplication> application;

@end

#endif /* ApplicationResponse_h */
