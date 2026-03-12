//
//  Response.h
//  captainup_sdk
//
//  Created by David Azriel on 09/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef Response_h
#define Response_h

#import "CPTObject.h"

/**
 Description
 */
@protocol CPTResponse <CPTObject>

/**
 The request status code
 @return the request status code. e.g. 200 for success.
 */
@property (nonatomic, readonly) NSInteger code;

/**
 Description
 */
@property (nonatomic, readonly, nullable) NSError *error;

/**
 The name of the object requested
 @return one of the following: "action"
 */
@property (nonatomic, readonly, nonnull) NSString *objectName;

/**
 The URL of the request
 @return the URL of the request
 */
@property (nonatomic, readonly, nonnull) NSString *requestUrl;

/**
 The API version
 @return the API version
 */
@property (nonatomic, readonly, nonnull) NSString *apiVersion;

/**
 Returns whether or not the request was successful
 @return <code>true</code> if the request was successful, <code>false</code> otherwise
 */
@property (nonatomic, readonly) BOOL isSuccessful;

@end

#endif /* Response_h */
