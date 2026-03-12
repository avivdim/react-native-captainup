//
//  CPTObject.h
//  captainup_sdk
//
//  Created by David Azriel on 02/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

typedef long CPTPoint;

#define RESPONSE_CALLBACK(response_type) nullable void(^)(response_type _Nullable response, NSError * _Nullable error)

/**
 A protocol which all captain up entity classes conform to.
 It exposes the original JSON Dictionary that the entity was created from.
 */
@protocol CPTObject <NSObject>

@optional
/**
 Use this dictionary in case an attribute is missing from the actual entity protocol.
 For example, if an attribute was added to the Captain Up REST services, but it is not yet
 reflected in the iOS SDK.
 For all other situations, use the specific entity protocol properties.
 */
@property (nonatomic, readonly, nonnull) NSDictionary<NSString*,id> *sourceDictionary;

@optional
/**
 If the CPTObject is based on a Captain Up API Object , then it also must know how to initialize itself from a JSON dictionary

 @param dictionary source dictionary
 @return return new instance
 */
- (nonnull instancetype)initWithDictionary:(nonnull NSDictionary<NSString*,id>*)dictionary;

- (nonnull instancetype)initWithDictionary:(nonnull NSDictionary*)dictionary andKey:(nonnull NSString *)key;
/**
 Any CPTObject must know how to transform itself to a JSON dictionary

 @return return NSDictionary object
 */
- (nonnull NSDictionary<NSString*,id>*)toDictionary;

@end
