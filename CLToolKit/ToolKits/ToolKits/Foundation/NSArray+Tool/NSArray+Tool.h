//
//  NSArray+Tool.h
//  ToolKits
//
//  Created by WuChunlong on 2017/2/19.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Tool)

@end

//  将JS文件中NULL转化为nil
@interface NSArray (NoNull)

- (NSArray *)cleanNullArr;

@end

@interface NSDictionary (NoNull)

- (NSDictionary *)cleanNull;

@end
