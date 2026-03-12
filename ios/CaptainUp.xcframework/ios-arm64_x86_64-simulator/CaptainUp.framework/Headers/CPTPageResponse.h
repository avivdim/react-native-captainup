//
//  PageResponse.h
//  captainup_sdk
//
//  Created by David Azriel on 14/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef PageResponse_h
#define PageResponse_h

#import "CPTResponse.h"

/**
 Description
 */
@protocol CPTPageResponse <CPTResponse>

/**
 The number of elements returned.
 */
@property (nonatomic, readonly) NSUInteger count;

/**
 The number of elemnts skipped in the pagination.
 */
@property (nonatomic, readonly) NSUInteger skip;

/**
 The number of elements that was requested
 */
@property (nonatomic, readonly) NSUInteger limit;

@end

#endif /* PageResponse_h */
