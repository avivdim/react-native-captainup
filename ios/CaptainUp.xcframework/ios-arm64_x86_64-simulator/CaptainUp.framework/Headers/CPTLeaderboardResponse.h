//
//  LeaderboardResponse.h
//  captainup_sdk
//
//  Created by David Azriel on 14/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef LeaderboardResponse_h
#define LeaderboardResponse_h

#import "CPTPageResponse.h"
#import "CPTLeaderboardTime.h"
#import "CPTUser.h"

/**
 CPTLeaderboardResponse
 */
@protocol CPTLeaderboardResponse <CPTPageResponse>

/**
 The leaderboard's type
 */
@property (nonatomic, readonly) CPTLeaderboardTime leaderboardTime;

/**
 The total number of players in the app
 */
@property (nonatomic, readonly) NSUInteger total;

/**
 List of all the players, ordered by their position in the leaderboard.
 Each element of the array conforms to the CPTUser protocol.
 */
@property (nonatomic, readonly, nonnull) NSArray<id<CPTUser>> *leaderboard;

@end

#endif /* LeaderboardResponse_h */
