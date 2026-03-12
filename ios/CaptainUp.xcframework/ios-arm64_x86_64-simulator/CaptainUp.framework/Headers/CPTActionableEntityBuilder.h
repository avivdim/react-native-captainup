//
//  ActionableEntityBuilder.h
//  CaptainUp
//
//  Created by David Azriel on 15/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ActionableEntityBuilder_h
#define ActionableEntityBuilder_h

#import "CPTActionableEntity.h"

/**
 A builder class for ActionableEntity objects.
 Use this builder to create entities to use with {@link ActionBuilder#setActionableEntity(ActionableEntity)}.
 */
@interface CPTActionableEntityBuilder : NSObject

/**
 Initializer

 @param builderBlock builderBlock description
 @return return value CPTActionableEntity object
 */
+ (nonnull id<CPTActionableEntity>)build:(nonnull void(^)(CPTActionableEntityBuilder * _Nonnull builder))builderBlock;

/**
 type
 */
@property (nonatomic, nonnull) NSString *type;

/**
 name
 */
@property (nonatomic, nonnull) NSString *name;

/**
 entityDescription
 */
@property (nonatomic, nonnull) NSString *entityDescription;

/**
 url
 */
@property (nonatomic, nonnull) NSString *url;

/**
 quantity
 */
@property (nonatomic) double quantity;

/**
 measurement
 */
@property (nonatomic, nonnull) NSString* measurement;

/**
 The entity's user defined parameters.
 @return a map between the parameter name and its value. Possible value types are Integer, Double, Long and String.
 */
@property (nonatomic, readonly, nonnull) NSMutableDictionary<NSString*,id> *extraParameters;

@end

#endif /* ActionableEntityBuilder_h */
