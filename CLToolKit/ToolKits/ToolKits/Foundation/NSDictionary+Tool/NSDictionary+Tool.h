//
//  NSDictionary+Tool.h
//  ToolKits
//
//  Created by WuChunlong on 2017/2/19.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (Tool)

@end



@interface NSDictionary(ObjectExt)

/**
 
 *  获取字典指定的NSDictionary的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空NSDictionary
 */
-(NSDictionary*)dictionaryObjectForKey:(id)aKey;

/**
 
 *获取字典指定的array的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 */
-(NSArray*)arrayObjectForKey:(id)aKey;

/**
 
 * 获取字典指定的对象为空是返回默认对象
 * @param aKey key
 * @param defaultObject value值如果为nil或者null会返回默认对象
 * @return 对象
 */
-(id)objectExtForKey:(id)aKey defaultObject:(id)defaultObject;

/**
 
 *获取字典指定的array的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 
 */
-(NSMutableArray*)mutableArrayObjectForKey:(id)aKey;

/**
 
 * @brief 如果akey找不到，返回@"" (防止出现nil，使程序崩溃)
 * @param aKey 字典key值
 * @return 字典value
 
 */
- (NSString *)stringForKey:(id)aKey;

/**
 
 * @brief @brief 如果akey找不到，返回默认值 (防止出现nil，使程序崩溃)
 * @param aKey 字典key值
 * @param defValue 为空时的默认值
 * @return 字典value
 */
- (NSString *)stringForKey:(id)aKey withDefaultValue:(NSString *)defValue;

/**
 
 * @brief 替换&nbsp;为空
 * @param aKey 字典key值
 * @return 字典value
 
 */
- (NSString *)replaceNBSPforKey:(id)aKey ;

/**
 
 *获取字典指定的key的数值字符
 * @param aKey key
 * @return value值如果为nil或者null会返回0字符串
 
 */
-(NSString*)numberStringForKey:(id)aKey;


@end



@interface NSDictionary (Merge)

/** 合并两个NSDictionary */
+ (NSDictionary *)dictionaryByMerging:(NSDictionary *)dict1 with:(NSDictionary *)dict2;

/** 并入一个NSDictionary */
- (NSDictionary *)dictionaryByMergingWith:(NSDictionary *)dict;

#pragma mark - Manipulation
- (NSDictionary *)dictionaryByAddingEntriesFromDictionary:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryByRemovingEntriesWithKeys:(NSSet *)keys;

@end


@interface NSDictionary (URL)

/**
 *  @brief  将url参数转换成NSDictionary
 *
 *  @param query url参数
 *
 *  @return NSDictionary
 */
+ (NSDictionary *)dictionaryWithURLQuery:(NSString *)query;

/**
 *  @brief  将NSDictionary转换成url 参数字符串
 *
 *  @return url 参数字符串
 */
- (NSString *)URLQueryString;

@end



