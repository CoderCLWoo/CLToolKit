//
//  WCLConstants.h
//  MyToolBox
//
//  Created by Wu on 2017/2/17.
//  Copyright © 2017年 Wu. All rights reserved.
//

#ifndef WCLConstants_h
#define WCLConstants_h

#import "Singleton.h"

#pragma mark - NSLog 处理

#ifdef __OBJC__

#ifdef DEBUG
//    #define NSLog(...)  NSLog(__VA_ARGS__)
    #define NSLog(fmt, ...)  NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
    #define NSLog(...)
#endif

#endif

#define WCL_DEPRECATED(explain) __attribute__((deprecated(explain)))
// eg: + (void)registerSubclass WCL_DEPRECATED("Deprecated in 1.6.0. Use `+[CYLPlusButton registerPlusButton]` instead.");

#ifdef __OBJC__
#pragma mark - 屏幕物理尺寸
#define WCL_ScreenHeight  [UIScreen mainScreen].bounds.size.height
#define WCL_ScreenWidth   [UIScreen mainScreen].bounds.size.width

#endif

#pragma mark -  视图尺寸、坐标
#define WCL_GetMinX(view) CGRectGetMinX(view.frame)//视图最小X坐标

#define WCL_GetMinY(view) CGRectGetMinY(view.frame)//视图最小Y坐标

#define WCL_GetMidX(view) CGRectGetMidX(view.frame)//视图中间X坐标

#define WCL_GetMidY(view) CGRectGetMidY(view.frame)//视图中间Y坐标

#define WCL_GetMaxX(view) CGRectGetMaxX(view.frame)//视图最大X坐标

#define WCL_GetMaxY(view) CGRectGetMaxY(view.frame)//视图最大Y坐标

#define WCL_GetWidth(view) CGRectGetWidth(view.frame)//视图宽度

#define WCL_GetHeight(view) CGRectGetHeight(view.frame)//视图高度

//自定义颜色
#define WCL_Color_RGBA(R,G,B,A) \
[UIColor colorWithRed:(R/255.0f) green:(G/255.0f) blue:(B/255.0f) alpha:A]

#endif /* WCLConstants_h */
