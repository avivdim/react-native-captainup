//
//  FieldSchema.h
//  captainup_sdk
//
//  Created by akerman zvi on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef FieldSchema_h
#define FieldSchema_h

#import "CPTObject.h"

/**
 CPTFieldSchema
 */
@protocol CPTFieldSchema <CPTObject>

/**
 field id
 */
@property (nonatomic, readonly, nonnull) NSString *fieldId;

/**
 The type of the field
 */
@property (nonatomic, readonly, nonnull) NSString *type;

/**
 The description of the field
 */
@property (nonatomic, readonly, nonnull) NSString *fieldDescription;

/**
 The name of the field
 */
@property (nonatomic, readonly, nonnull) NSString *name;

@end

#endif /* FieldSchema_h */
