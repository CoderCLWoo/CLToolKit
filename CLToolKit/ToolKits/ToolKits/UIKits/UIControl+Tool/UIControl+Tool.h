//
//  UIControl+Tool.h
//  ToolKits
//
//  Created by WuChunlong on 2017/2/20.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIControl (Tool)

@end


@interface UIControl (Delay)

/** 每次响应的间隔 */
@property (assign, nonatomic) NSTimeInterval acceptEventInterval;

@end
