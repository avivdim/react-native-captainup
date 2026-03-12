//
//  ConditionProgress.h
//  captainup_sdk
//
//  Created by David Azriel on 02/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ConditionProgress_h
#define ConditionProgress_h

#import "CPTObject.h"

/**
 CPTConditionProgress
 */
@protocol CPTConditionProgress <CPTObject>

/**
 The number of times the user passed this condition so far
 */
@property (nonatomic, readonly) NSUInteger times;

/**
 The number of times the user repeatedly passed this condition
 */
@property (nonatomic, readonly) NSUInteger repeatTimes;

@end

#endif /* ConditionProgress_h */
