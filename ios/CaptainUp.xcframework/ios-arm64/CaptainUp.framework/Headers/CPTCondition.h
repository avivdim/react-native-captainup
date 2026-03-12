//
//  Condition.h
//  captainup_sdk
//
//  Created by David Azriel on 02/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef Condition_h
#define Condition_h

#import "CPTObject.h"

/**
 CPTCondition Object
 */
@protocol CPTCondition <CPTObject>

/**
 condition id
 */
@property (nonatomic, readonly, nonnull) NSString *conditionId;

/**
 condition type
 */
@property (nonatomic, readonly, nonnull) NSString *type;

/**
 condition description
 */
@property (nonatomic, readonly, nonnull) NSString *conditionDescription;

@end

#endif /* Condition_h */
