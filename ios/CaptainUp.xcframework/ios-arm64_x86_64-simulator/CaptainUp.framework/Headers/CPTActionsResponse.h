//
//  ActionsResponse.h
//  captainup_sdk
//
//  Created by David Azriel on 10/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ActionsResponse_h
#define ActionsResponse_h

#import "CPTPageResponse.h"
#import "CPTActionType.h"
#import "CPTAction.h"

/**
 Description
 */
@protocol CPTActionsResponse <CPTPageResponse>

/**
 CPTActionType
 */
@property (nonatomic, readonly) CPTActionType actionType;

/**
 List of the actions, sorted by their date, starting from the most recent action.
 Each element of the array conforms to the CPTAction protocol.
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTAction>> *actions;

@end

#endif /* ActionsResponse_h */
