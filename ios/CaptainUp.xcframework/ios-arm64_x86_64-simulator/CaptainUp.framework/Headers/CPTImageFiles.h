//
//  CPTImageFiles.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 5/29/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#ifndef CPTImageFiles_h
#define CPTImageFiles_h

#import "CPTObject.h"

/**
 Defines the images to be used for some Captain Up Object.
 */
@protocol CPTImageFiles <CPTObject>

/**
 Image url
 */
@property (nonatomic, readonly, nullable) NSString* imageURL;

/**
 Image thumbnail ulr
 */
@property (nonatomic, readonly, nullable) NSString* thumbnailImageURL;

/**
 present image
 */
@property (nonatomic, readonly, nullable) NSString* presetImage;

@end

#endif /* CPTImageFiles_h */
