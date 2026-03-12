//
//  CPTCurrency.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 3/9/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef CPTCurrency_h
#define CPTCurrency_h

#import "CPTObject.h"

/**
 Currency Object, can be used to know the total amount of currency a player has, or the amount of currency received by an action, a badge, an asset etc..
 */
@protocol CPTCurrency <CPTObject>

/**
 currency name
 */
@property (nonatomic, readonly, nonnull) NSString* name;

/**
  amount of currency
 */
@property (nonatomic, readonly) NSInteger amount;

/**
 amount received
 */
@property (nonatomic, readonly) NSInteger amountReceived;

/**
 multiplier
 */
@property (nonatomic, readonly) NSUInteger multiplier;

/**
 player total
 */
@property (nonatomic, readonly) NSUInteger playerTotal;


@end


#endif /* CPTCurrency_h */
