//
//  ImageFilesClass.h
//  CaptainUp
//
//  Created by Yogesh Prajapati on 5/29/17.
//  Copyright © 2017 Captain Up. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPTImageFiles.h"

@interface CPTImageFiles : NSObject <CPTImageFiles>

- (BOOL)isEqualToImageFiles:(CPTImageFiles*)other;

-(instancetype)initWithImageUrl:(NSString*)imageUrl_ andThumbnailImageURL:(NSString*) thumbnailImageURL_ andPresetImage:(NSString*)presetImage_;

@end
