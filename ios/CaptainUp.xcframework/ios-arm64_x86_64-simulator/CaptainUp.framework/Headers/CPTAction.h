//
//  Action.h
//  captainup_sdk
//
//  Created by David Azriel on 02/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPTActionableEntity.h"
#import "CPTCurrency.h"

/**
 Actions are the backbone of the Captain Up platform.
 Apps can gain deep insights on their users based on their actions; segment, engage, interact and
 incentivize their users based on user behavior, and incentivize users with points, badges,
 levels, rewards and messages for doing these actions.
 Captain Up supports completely dynamic actions, and every site and app can create and customize
 their own actions and how the experience evolves around them. You might want to think of actions
 as natural-language sentences comprised of subject, verb, and object: In the sentence
 "The Captain liked Game of Thrones", The Captain is the subject – the user who did the action;
 liked is the verb, describing what type of action went on; and Game of Thrones is the
 {@link CPTActionableEntity object}.
 involved in the action.Actions are the backbone of the Captain Up platform.
 Apps can gain deep insights on their users based on their actions; segment, engage, interact and
 incentivize their users based on user behavior, and incentivize users with points, badges,
 levels, rewards and messages for doing these actions.
 Captain Up supports completely dynamic actions, and every site and app can create and customize
 their own actions and how the experience evolves around them. You might want to think of actions
 as natural-language sentences comprised of subject, verb, and object: In the sentence
 "The Captain liked Game of Thrones", The Captain is the subject – the user who did the action;
 liked is the verb, describing what type of action went on; and Game of Thrones is the
 {@link CPTActionableEntity object}.
 involved in the action.
 */
@protocol CPTAction <CPTObject>

/**
 The id of the action
 */
@property (nonatomic, readonly, nullable) NSString *actionId;

/**
 The name of the action
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 The action timestamp. For Action requests (such as createAction), do not set this property
 (or set it to <code>null</code>). The timestamp property cannot be set from a mobile
 application.
 */
@property (nonatomic, readonly, nonnull) NSDate* timestamp;

/**
 The ID of the user that did the action
 */
@property (nonatomic, readonly, nonnull) NSString *playerId;

/**
 The action object information
 */
@property (nonatomic, readonly, nonnull) id<CPTActionableEntity> entity;

/**
Action currencies
 */
@property (nonatomic ,readonly, nonnull) NSDictionary<NSString*,id<CPTCurrency>>* currencies;

@end
