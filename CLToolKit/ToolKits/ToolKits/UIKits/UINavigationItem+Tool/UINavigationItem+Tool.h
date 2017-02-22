//
//  UINavigationItem+Tool.h
//  ToolKits
//
//  Created by WuChunlong on 2017/2/20.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationItem (Tool)

@end


// https://github.com/Just-/UINavigationItem-Loading
@interface UINavigationItem (Loading)
/** 在navigationbar上显示UIActivityIndicatorView的位置*/
typedef NS_ENUM(NSUInteger, NavBarLoaderPosition)
{
    NavBarLoaderPositionCenter = 0,
    
    NavBarLoaderPositionLeft,
    
    NavBarLoaderPositionRight
};

/** 开始在position位置显示UIActivityIndicatorView */
- (void)startAnimatingAt:(NavBarLoaderPosition)position;

/** 结束显示UIActivityIndicatorView*/
- (void)stopAnimating;

@end



//https://github.com/devxoul/UINavigationItem-Margin
FOUNDATION_EXPORT double UINavigationItem_MarginVersionNumber;
FOUNDATION_EXPORT const unsigned char UINavigationItem_MarginVersionString[];

@interface UINavigationItem (Margin)

@property (nonatomic, assign) CGFloat leftMargin;
@property (nonatomic, assign) CGFloat rightMargin;

+ (CGFloat)systemMargin;

@end


