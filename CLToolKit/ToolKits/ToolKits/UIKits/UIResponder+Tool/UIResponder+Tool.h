//
//  UIResponder+Tool.h
//  ToolKits
//
//  Created by WuChunlong on 2017/2/19.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIResponder (Tool)

@end


//https://github.com/thad/ExampleFindFirstResponder
@interface UIResponder (FirstResponder)
/**
 *  @brief  当前第一响应者
 *
 *  @return 当前第一响应者
 */
+ (id)currentFirstResponder;

@end
