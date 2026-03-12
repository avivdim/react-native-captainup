//
//  QueryBuilder.h
//  captainup_sdk
//
//  Created by David Azriel on 10/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef QueryBuilder_h
#define QueryBuilder_h

#import "CPTQuery.h"

/**
 Used to create a {@link CTOQuery} object.
 */
@interface CPTQueryBuilder : NSObject

/**
 Description

 @param builderBlock builderBlock description
 @return return value description
 */
+ (nonnull id<CPTQuery>)build:(nonnull void(^)(CPTQueryBuilder * _Nonnull builder))builderBlock;

/**
 Description
 */
- (void)returnAllRecords;

/**
 Description
 */
@property (nonatomic) NSUInteger skip;

/**
 Description
 */
@property (nonatomic) NSUInteger limit;

/**
 Description
 */
@property (nonatomic) BOOL extended;

@end

#endif /* QueryBuilder_h */
