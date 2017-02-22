//
//  NSDictionary+Tool.m
//  ToolKits
//
//  Created by WuChunlong on 2017/2/19.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import "NSDictionary+Tool.h"
#import "NSString+Tool.h"

@implementation NSDictionary (Tool)

@end


@implementation NSDictionary(ObjectExt)

/**
 
 *获取字典指定的NSDictionary的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 
 */
-(NSDictionary*)dictionaryObjectForKey:(id)aKey

{
    
    id value = [self objectForKey:aKey];
    if (value == nil || [value isKindOfClass:[NSNull class]]||![value isKindOfClass:[NSDictionary class]])
    {
        return nil;
        
    }
    
    return value;
    
}

/**
 
 *获取字典指定的array的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 
 */
-(NSArray*)arrayObjectForKey:(id)aKey

{
    
    id value = [self objectForKey:aKey];
    if (value == nil || [value isKindOfClass:[NSNull class]])
    {
        return nil;
        
    }
    
    return value;
    
}

/**
 
 *获取字典指定的array的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 
 */
-(NSMutableArray*)mutableArrayObjectForKey:(id)aKey

{
    
    id value = [self objectForKey:aKey];
    
    if (value == nil || [value isKindOfClass:[NSNull class]])
        
    {
        
        return nil;
        
    }
    
    return value;
    
}

/**
 * 获取字典指定的对象为空是返回默认对象
 * @param aKey key
 * @param defaultObject value值如果为nil或者null会返回默认对象
 * @return 对象
 
 */
-(id)objectExtForKey:(id)aKey defaultObject:(id)defaultObject

{
    
    id value = [self objectForKey:aKey];
    
    if (value == nil || [value isKindOfClass:[NSNull class]])
        
    {
        
        return defaultObject;
        
    }
    
    return value;
    
}

/**
 
 * @brief 如果akey找不到，返回@"" (防止出现nil，使程序崩溃)
 * @param aKey 字典key值
 * @return 字典value
 
 */
- (NSString*) stringForKey:(id)aKey
{
    
    return [self stringForKey:aKey withDefaultValue:@""];
    
}

/**
 
 *获取字典指定的key的数值字符
 * @param aKey key
 * @return value值如果为nil或者null会返回0字符串
 
 */
-(NSString*)numberStringForKey:(id)aKey

{
    
    return [self stringForKey:aKey withDefaultValue:@"0"];
    
}

/**
 
 * @brief @brief 如果akey找不到，返回默认值 (防止出现nil，使程序崩溃)
 * @param aKey 字典key值
 * @param defValue 为空时的默认值
 * @return 字典value
 
 */
- (NSString *)stringForKey:(id)aKey withDefaultValue:(NSString *)defValue

{
    
    NSString *value = [self objectForKey:aKey];
    
    if (value == nil || [value isKindOfClass:[NSNull class]])
        
    {
        
        value = defValue;
        
    }
    
    return [[NSString stringWithFormat:@"%@",value] replaceNullString];
    
}

/**
 
 * @brief 替换&nbsp;为空
 * @param aKey 字典key值
 * @return 字典value
 
 */
-(NSString*)replaceNBSPforKey:(id)aKey

{
    
    NSString *value = [self objectForKey:aKey];
    
    if (!value)
        
    {
        
        value = @"";
        
    }
    
    NSString* str = [value stringByReplacingOccurrencesOfString:@"&nbsp;" withString:@" "] ;
    
    return [[NSString stringWithFormat:@"%@",str] replaceNullString];
    
}
@end




@implementation NSDictionary (Merge)

+ (NSDictionary *)dictionaryByMerging:(NSDictionary *)dict1 with:(NSDictionary *)dict2
{
    NSMutableDictionary * result = [NSMutableDictionary dictionaryWithDictionary:dict1];
    NSMutableDictionary * resultTemp = [NSMutableDictionary dictionaryWithDictionary:dict1];
    [resultTemp addEntriesFromDictionary:dict2];
    
    [resultTemp enumerateKeysAndObjectsUsingBlock: ^(id key, id obj, BOOL *stop) {
        if ([dict1 objectForKey:key])
        {
            if ([obj isKindOfClass:[NSDictionary class]])
            {
                NSDictionary * newVal = [[dict1 objectForKey: key] dictionaryByMergingWith: (NSDictionary *) obj];
                [result setObject: newVal forKey: key];
            }
            else
            {
                [result setObject: obj forKey: key];
            }
        }
        else if([dict2 objectForKey:key])
        {
            if ([obj isKindOfClass:[NSDictionary class]])
            {
                NSDictionary * newVal = [[dict2 objectForKey: key] dictionaryByMergingWith: (NSDictionary *) obj];
                [result setObject: newVal forKey: key];
            }
            else
            {
                [result setObject: obj forKey: key];
            }
        }
    }];
    return (NSDictionary *) [result mutableCopy];
    
}

- (NSDictionary *)dictionaryByMergingWith:(NSDictionary *)dict
{
    return [[self class] dictionaryByMerging:self with: dict];
}

#pragma mark - Manipulation
- (NSDictionary *)dictionaryByAddingEntriesFromDictionary:(NSDictionary *)dictionary
{
    NSMutableDictionary *result = [self mutableCopy];
    [result addEntriesFromDictionary:dictionary];
    return result;
}

- (NSDictionary *)dictionaryByRemovingEntriesWithKeys:(NSSet *)keys
{
    NSMutableDictionary *result = [self mutableCopy];
    [result removeObjectsForKeys:keys.allObjects];
    return result;
}

@end




@implementation NSDictionary (URI)
/**
 *  @brief  将url参数转换成NSDictionary
 *
 *  @param query url参数
 *
 *  @return NSDictionary
 */
+ (NSDictionary *)dictionaryWithURLQuery:(NSString *)query
{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSArray *parameters = [query componentsSeparatedByString:@"&"];
    for(NSString *parameter in parameters)
    {
        NSArray *contents = [parameter componentsSeparatedByString:@"="];
        if([contents count] == 2)
        {
            NSString *key = [contents objectAtIndex:0];
            NSString *value = [contents objectAtIndex:1];
            value = [value stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
            if (key && value)
            {
                [dict setObject:value forKey:key];
            }
        }
    }
    return [NSDictionary dictionaryWithDictionary:dict];
}
/**
 *  @brief  将NSDictionary转换成url 参数字符串
 *
 *  @return url 参数字符串
 */
- (NSString *)URLQueryString
{
    NSMutableString *string = [NSMutableString string];
    for (NSString *key in [self allKeys])
    {
        if ([string length])
        {
            [string appendString:@"&"];
        }
        CFStringRef escaped = CFURLCreateStringByAddingPercentEscapes(NULL,(CFStringRef)[[self objectForKey:key] description],
                                                                      NULL,(CFStringRef)@"!*'();:@&=+$,/?%#[]",
                                                                      kCFStringEncodingUTF8);
        [string appendFormat:@"%@=%@", key, escaped];
        CFRelease(escaped);
    }
    return string;
}
@end


