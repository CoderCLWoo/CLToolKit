//
//  NSArray+Tool.m
//  ToolKits
//
//  Created by WuChunlong on 2017/2/19.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import "NSArray+Tool.h"

@implementation NSArray (Tool)

@end


@implementation NSArray (NoNull)

- (NSArray *)cleanNullArr {
    
    NSMutableArray *arr = [[NSMutableArray alloc] initWithArray:self];
    
    int i = 0;
    for (id value in  self) {
        
        if ([value isKindOfClass:[NSNull class]]) {
            [arr replaceObjectAtIndex:i withObject:@"NULL"];
            
        }else if ([value isKindOfClass:[NSDictionary class]]) {
            
            NSDictionary *newDic = [value cleanNull];
            
            [arr replaceObjectAtIndex:i withObject:newDic];
            
        }
        i ++;
        
    }
    
    return [[NSArray alloc] initWithArray:arr];
}

@end


@implementation NSDictionary (NoNull)

- (NSDictionary *)cleanNull {
    
    NSMutableDictionary *dic = [[NSMutableDictionary alloc] initWithDictionary:self];;
    
    for (NSString *key in [(NSDictionary *)self allKeys]) {
        
        if ([[dic objectForKey:key] isKindOfClass:[NSNull class]]) {
            
            [dic setObject:@"-NULL" forKey:key];
        }else if ([[dic objectForKey:key] isKindOfClass:[NSDictionary class]]) {
            
            NSDictionary *newDic = [[dic objectForKey:key] cleanNull];
            
            [dic setObject:newDic forKey:key];
            
        }else if ([[dic objectForKey:key] isKindOfClass:[NSArray class]]) {
            
            NSArray *arr = [(NSArray *)[dic objectForKey:key] cleanNullArr];
            
            [dic setObject:arr forKey:key];
            
        }
        
    }
    return [[NSDictionary alloc] initWithDictionary:dic];
    
}

@end
