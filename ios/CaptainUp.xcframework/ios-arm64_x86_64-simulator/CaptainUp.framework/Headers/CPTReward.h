//
//  CPTReward.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 1/30/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPTRewardType.h"
#import "CPTObject.h"
#import "CPTRewardData.h"
@protocol CPTClaimResponse;


#ifndef CPTReward_h
#define CPTReward_h

/**
 Description
 */
@protocol CPTReward <CPTObject,NSCopying>

/**
 The ID of the reward
 */
@property (nonatomic, readonly, nonnull) NSString* rewardId;

/**
 The name of the reward
 */
@property (nonatomic, readonly, nonnull) NSString* name;

/**
 The name of the reward
 */
@property (nonatomic, readonly, nonnull) NSString* rewardDescription;

/**
 The type of the reward
 */
@property (nonatomic, readonly, nonnull) NSString* type;

/**
 Reward amount
 */
@property (nonatomic, readonly) NSUInteger amount;

/**
 Reward type id
 */
@property (nonatomic, readonly, nonnull) NSString* rewardTypeId;

/**
 
 */
@property (nonatomic, readonly, nullable) NSDictionary<NSString*,id<CPTRewardData>>* data;

/**
 get reward type

 @return return CPTRewardType reward type
 */
-(nonnull id<CPTRewardType>)getRewardType;

-(nullable id<CPTRewardData>)getDataByName:(nonnull NSString*)fieldName;

/**
 Get data value of String type
 
 @param fieldName the field name you want to retrieve
 @return the value as a String or null if no value was found
 */
-(nullable NSString*)getStringByName:(nonnull NSString*)fieldName;

/**
 Get data value of number type
 
 @param fieldName the field name you want to retrieve
 @return the value as a int or 0 if no value was found
 */
-(NSUInteger)getNumberByName:(nonnull NSString*)fieldName;

/**
 Get data value of Array type
 
 @param fieldName the field name you want to retrieve
 @return the value as a ArrayList<String> or null if no value was found
 */
-(nullable NSArray<NSString*>*)getArrayByName:(nonnull NSString*)fieldName;


/**
 Preforms Synchronous claim action
 */
-(void)claim;

/**
 Performs Asynchronus claim action
 @param callback void(^)(id<CPTClaimResponse> response, NSError *error)
 */
- (void)claim:(RESPONSE_CALLBACK(id<CPTClaimResponse>))callback;


@end

#endif /* CPTReward_h */
