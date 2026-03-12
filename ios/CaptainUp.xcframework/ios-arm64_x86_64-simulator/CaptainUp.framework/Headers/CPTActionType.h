//
//  ActionType.h
//  captainup_sdk
//
//  Created by David Azriel on 10/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ActionType_h
#define ActionType_h

/**
 Description

 - CPTActionTypePublic: CPTActionTypePublic description
 - CPTActionTypePrivate: CPTActionTypePrivate description
 - CPTActionTypeInbox: CPTActionTypeInbox description
 - CPTActionTypeUnknown: CPTActionTypeUnknown description
 */
typedef NS_ENUM(NSInteger, CPTActionType) {
    CPTActionTypePublic,
    CPTActionTypePrivate,
    CPTActionTypeInbox,
    CPTActionTypeUnknown
};

#endif /* ActionType_h */
