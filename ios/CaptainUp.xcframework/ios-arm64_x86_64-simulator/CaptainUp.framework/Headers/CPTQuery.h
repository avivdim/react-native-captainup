//
//  Query.h
//  captainup_sdk
//
//  Created by David Azriel on 10/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef Query_h
#define Query_h

/**
 Description
 */
@protocol CPTQuery

/**
 Description
 */
@property (nonatomic, readonly) NSUInteger skip;

/**
 Description
 */
@property (nonatomic, readonly) NSUInteger limit;

/**
 Description
 */
@property (nonatomic, readonly) BOOL extended;

@end

#endif /* Query_h */
