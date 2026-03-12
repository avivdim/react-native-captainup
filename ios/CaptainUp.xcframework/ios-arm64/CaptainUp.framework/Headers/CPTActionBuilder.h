//
//  ActionBuilder.h
//  CaptainUp
//
//  Created by David Azriel on 15/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ActionBuilder_h
#define ActionBuilder_h

#include "CPTAction.h"

/**
 Used to build an {@link CPTAction} object to send for Captain Up Requests.
 Only properties which are allowed to be set from a mobile application appear in the builder.
 */
@interface CPTActionBuilder : NSObject

/**
 Action builder

 @param builderBlock builderBlock description
 @return return CPTActionBuilder
 */
+ (nonnull id<CPTAction>)build:(nonnull void(^)(CPTActionBuilder * _Nonnull builder))builderBlock;

/**
 name of the action
 */
@property (nonatomic, nonnull) NSString *name;

/**
 The action object infomration
 */
@property (nonatomic, nonnull) id<CPTActionableEntity> entity;

@end

#endif /* ActionBuilder_h */
