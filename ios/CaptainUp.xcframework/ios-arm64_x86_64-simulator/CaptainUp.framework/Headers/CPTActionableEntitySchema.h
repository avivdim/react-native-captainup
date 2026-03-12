//
//  ActionableEntitySchema.h
//  captainup_sdk
//
//  Created by akerman zvi on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ActionableEntitySchema_h
#define ActionableEntitySchema_h

#import "CPTObject.h"
#import "CPTFieldSchema.h"

/**
 
 */
@protocol CPTActionableEntitySchema <CPTObject>

@property (nonatomic, readonly, nonnull) NSString *schemaId;

/**
 The determiner for the entity name. i.e. "a".
 */
@property (nonatomic, readonly, nonnull) NSString *determiner;

/**
 The name of the entity
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 The plural name of the entity
 */
@property (nonatomic, readonly, nonnull) NSString *plural;

/**
List of available fields of the entity.
Each element of the list implements the protocol CPTFieldSchema.
 */
@property (nonatomic, readonly, nonnull) NSArray<id <CPTFieldSchema>> *fieldSchemas;

@end

#endif /* ActionableEntitySchema_h */
