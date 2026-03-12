//
//  UserResponse.h
//  captainup_sdk
//
//  Created by David Azriel on 09/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef UserResponse_h
#define UserResponse_h

#import "CPTResponse.h"
#import "CPTUser.h"

/**
 Description
 */
@protocol CPTUserResponse <CPTResponse>

/**
 user object
 */
@property (nonatomic, readonly, nonnull) id<CPTUser> user;

@end

#endif /* UserResponse_h */
