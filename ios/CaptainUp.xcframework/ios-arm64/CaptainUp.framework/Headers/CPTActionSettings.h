//
//  ActionSettings.h
//  captainup_sdk
//
//  Created by David Azriel on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ActionSettings_h
#define ActionSettings_h

#import "CPTObject.h"
#import "CPTActionableEntitySchema.h"

/**
 
 */
@protocol CPTActionSettings <CPTObject>

// The ID of the Action
@property (nonatomic, readonly, nullable) NSString *actionId;

// The name of the action
@property (nonatomic, readonly, nullable) NSString *name;

// The number of pointa that will be awarded to the user for doing the action
@property (nonatomic, readonly) CPTPoint points;

// The points interval
@property (nonatomic, readonly) CPTPoint pointsInterval;

// Whether to show a leaderboard for this action
@property (nonatomic, readonly) BOOL hasLeaderboard;

// Whether to show an activity for this action
// returns YES when the action will show in a player's activity log, NO otherwise.
@property (nonatomic, readonly) BOOL showActivity;

// Whether to show a notification for this action.
// returns YES if the action will also generate a notification, NO otherwise.
@property (nonatomic, readonly) BOOL showNotification;

// The past tense of the action
@property (nonatomic, readonly, nullable) NSString *pastTense;

// The present proressive tense of the action
@property (nonatomic, readonly, nullable) NSString *presentProgressiveTense;

// The URL to the action's image
@property (nonatomic, readonly, nonnull) NSString *imageURL;

// The action's entities schema definition
// Each element in the array is an object that implements the protocol CPTActionableEntitySchema
@property (nonatomic, readonly, nonnull) NSArray<id <CPTActionableEntitySchema>> *entitySchemas;

@end

#endif /* ActionSettings_h */
