//
//  CPTSignedIntegrationUser.h
//  CaptainUp
//
//  Created by David Azriel on 13/01/2016.
//  Copyright © 2016 Captain Up. All rights reserved.
//

#ifndef CPTSignedIntegrationUser_h
#define CPTSignedIntegrationUser_h

#import "CPTIntegrationUser.h"

/**
 Identified a securely signed integration user
 */
@protocol CPTSignedIntegrationUser <CPTIntegrationUser>

/**
 signature
 */
@property (nonatomic, readonly, nonnull) NSString *signature;

@end


#endif /* CPTSignedIntegrationUser_h */
