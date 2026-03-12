//
//  LeaderboardTime.h
//  captainup_sdk
//
//  Created by David Azriel on 07/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef LeaderboardTime_h
#define LeaderboardTime_h

/**
 CPTLeaderboardTime

 - CPTLeaderboardTimeUnknown: CPTLeaderboardTimeUnknown description
 - CPTLeaderboardTimeDaily: CPTLeaderboardTimeDaily description
 - CPTLeaderboardTimeWeekly: CPTLeaderboardTimeWeekly description
 - CPTLeaderboardTimeMonthly: CPTLeaderboardTimeMonthly description
 - CPTLeaderboardTimeAll: CPTLeaderboardTimeAll description
 */
typedef NS_ENUM(NSInteger, CPTLeaderboardTime) {
    CPTLeaderboardTimeUnknown,
    CPTLeaderboardTimeDaily,
    CPTLeaderboardTimeWeekly,
    CPTLeaderboardTimeMonthly,
    CPTLeaderboardTimeAll
};

#endif /* LeaderboardTime_h */
