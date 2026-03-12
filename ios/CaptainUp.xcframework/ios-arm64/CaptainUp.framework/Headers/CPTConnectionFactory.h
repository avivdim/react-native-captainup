//
//  ConnectionFactory.h
//  CaptainUp
//
//  Created by David Azriel on 15/12/2015.
//  Copyright © 2015 Captain Up. All rights reserved.
//

#ifndef ConnectionFactory_h
#define ConnectionFactory_h

#import <CaptainUp/CPTConnection.h>

/**
 The entry point to the Captain Up SDK.
 Use this factory to create {@link CaptainUpConnection Captain Up Connections}.
 */
@interface CPTConnectionFactory : NSObject

/**
 CPTConnectionFactory initializer to connect to server.

 @param url String server url
 @param appId String Application id
 @param mobileToken String Mobile app token
 @return return CPTConnection connection object
 */
+ (nonnull id<CPTConnection>)connectTo:(nonnull NSString *)url forApp:(nonnull NSString *)appId withMobileToken:(nonnull NSString *)mobileToken;

@end

#endif /* ConnectionFactory_h */
