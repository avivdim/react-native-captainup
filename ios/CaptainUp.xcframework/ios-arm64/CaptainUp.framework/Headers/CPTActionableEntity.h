//
//  ActionableEntity.h
//  captainup_sdk
//
//  Created by David Azriel on 30/11/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ActionableEntity_h
#define ActionableEntity_h

#import "CPTObject.h"

/**
 An action's object information.
 */
@protocol CPTActionableEntity <CPTObject>

/**
 The entity's type
 */
@property (nonatomic, readonly, nonnull) NSString *type;

/**
 The entity's name
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 The entity's description
 */
@property (nonatomic, readonly, nonnull) NSString *entityDescription;

/**
 The entity's url
 */
@property (nonatomic, readonly, nonnull) NSString *url;

/**
 The entity's quantity
 */
@property (nonatomic, readonly) double quantity;

/**
 The entity's measurment
 */
@property (nonatomic, readonly, nonnull) NSString* measurement;

/**
 The entity's user defined parameters.
 a map between the parameter name and its value. Possible value types are Integer, Double, Long and String.
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString*,id> *extraParameters;

@end

#endif /* ActionableEntity_h */
