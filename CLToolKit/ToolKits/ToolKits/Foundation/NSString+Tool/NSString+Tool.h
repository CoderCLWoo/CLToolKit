//
//  NSString+Tool.h
//  ToolKits
//
//  Created by WuChunlong on 2017/2/19.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (Tool)

@end


@interface NSString (Hash)

@property (readonly) NSString *md5String;
@property (readonly) NSString *sha1String;
@property (readonly) NSString *sha256String;
@property (readonly) NSString *sha512String;

- (NSString *)hmacSHA1StringWithKey:(NSString *)key;
- (NSString *)hmacSHA256StringWithKey:(NSString *)key;
- (NSString *)hmacSHA512StringWithKey:(NSString *)key;

@end



@interface NSString (MD5)
+ (NSString *)md5:(NSString *)originalStr;
@end



#define __BASE64( text )        [NSString base64StringFromText:text]
#define __TEXT( base64 )        [NSString textFromBase64String:base64]
@interface NSString (base64)
/******************************************************************
 函数名称 : + (NSString *)base64StringFromText:(NSString *)text
 函数描述 : 将文本转换为base64格式字符串
 输入参数 : (NSString *)text    文本
 输出参数 : N/A
 返回参数 : (NSString *)    base64格式字符串
 备注信息 :
 ***************************************************************/
+ (NSString *)base64StringFromText:(NSString *)text;

/******************************************************************
 函数名称 : + (NSString *)textFromBase64String:(NSString *)base64
 函数描述 : 将base64格式字符串转换为文本
 输入参数 : (NSString *)base64  base64格式字符串
 输出参数 : N/A
 返回参数 : (NSString *)    文本
 备注信息 :
 *****************************************************************/
+ (NSString *)textFromBase64String:(NSString *)base64;


@end


@interface NSString (Extensions)
- (NSString *)lowercaseFirstCharacter;
- (NSString *)uppercaseFirstCharacter;
- (BOOL)isEmpty;
- (NSString *)replaceNullString;
- (NSString *)trim;
- (NSString *)trimTheExtraSpaces;
- (NSString *)escapeHTML;
- (NSString *)stringByDecodingXMLEntities;
- (NSString *)md5;
- (NSString *)md5ForUTF16;
- (CGFloat)fontSizeWithFont:(UIFont *)font constrainedToSize:(CGSize)size;
- (NSMutableArray *)tokenizationStringByNSStringEnumerationOptions:(NSStringEnumerationOptions)opts;
- (NSString *)languageForString;
- (NSMutableArray *)analyseTextOfSentences;
// app的版本
+ (NSString *)appVersion;
// 手机机型
+ (NSString *)deviceModel;

// 获取Documents路径
+ (NSString *)documentPath;

// 获取缓存路径
+ (NSString *)cachePath;

+ (NSString *)imageCachePath;


//! 是否是合法邮箱
- (BOOL)isValidEmail;
//! 是否是合法号码
- (BOOL)isValidPhoneNumber;
//! 是否是合法的18位身份证号码
- (BOOL)isValidPersonID;
/**
 * 功能:判断是否在地区码内
 * 参数:地区码
 */
- (BOOL)areaCode:(NSString *)code;

//! 根据文件名返回路径
+ (NSString *)pathWithFileName:(NSString *)fileName;
+ (NSString *)pathWithFileName:(NSString *)fileName ofType:(NSString *)type;

// 根据秒数返回日期
+ (NSString *)dateWithSeconds:(NSUInteger)seconds;

@end



@interface NSString (Contains)

/** 判断URL中是否包含中文 */
- (BOOL)isContainChinese;

/** 获取字符数量 */
- (int)wordsCount;

@end



@interface NSString (DictionaryValue)

/** JSON字符串转成NSDictionary */
-(NSDictionary *)dictionaryValue;

@end



//https://github.com/damienromito/NSString-Matcher
@interface NSString(Matcher)

- (NSArray *)matchWithRegex:(NSString *)regex;

- (NSString *)matchWithRegex:(NSString *)regex atIndex:(NSUInteger)index;

- (NSString *)firstMatchedGroupWithRegex:(NSString *)regex;

- (NSTextCheckingResult *)firstMatchedResultWithRegex:(NSString *)regex;

@end



@interface NSString (NormalRegex)
/**
 *  手机号码的有效性:分电信、联通、移动和小灵通
 */
- (BOOL)isMobileNumberClassification;
/**
 *  手机号有效性
 */
- (BOOL)isMobileNumber;

/**
 *  邮箱的有效性
 */
- (BOOL)isEmailAddress;

/**
 *  简单的身份证有效性
 *
 */
- (BOOL)simpleVerifyIdentityCardNum;

/**
 *  精确的身份证号码有效性检测
 *
 *  @param value 身份证号
 */
+ (BOOL)accurateVerifyIDCardNumber:(NSString *)value;

/**
 *  车牌号的有效性
 */
- (BOOL)isCarNumber;

/**
 *  银行卡的有效性
 */
- (BOOL)bankCardluhmCheck;

/**
 *  IP地址有效性
 */
- (BOOL)isIPAddress;

/**
 *  Mac地址有效性
 */
- (BOOL)isMacAddress;

/**
 *  网址有效性
 */
- (BOOL)isValidUrl;

/**
 *  纯汉字
 */
- (BOOL)isValidChinese;

/**
 *  邮政编码
 */
- (BOOL)isValidPostalcode;

/**
 *  工商税号
 */
- (BOOL)isValidTaxNo;

@end



// https://github.com/croath/NSString-Pinyin
@interface NSString (Pinyin)

- (NSString*)pinyinWithPhoneticSymbol;

- (NSString*)pinyin;

- (NSArray*)pinyinArray;

- (NSString*)pinyinWithoutBlank;

- (NSArray*)pinyinInitialsArray;

- (NSString*)pinyinInitialsString;

@end


@interface NSString (Size)

- (CGFloat)heightWithFont:(UIFont *)font constrainedToWidth:(CGFloat)width;

- (CGFloat)widthWithFont:(UIFont *)font constrainedToHeight:(CGFloat)height;


- (CGSize)sizeWithFont:(UIFont *)font constrainedToWidth:(CGFloat)width;

- (CGSize)sizeWithFont:(UIFont *)font constrainedToHeight:(CGFloat)height;


+ (NSString *)reverseString:(NSString *)strSrc;

@end




@interface NSString (StringPages)
/**
 *  根据字符串进行分页
 *
 *  @param cache 需要进行分页的字符串
 *  @param font  你想显示的字体大小，这个要保持统一
 *  @param r     你想在多大的窗口显示
 *
 *  @return 返回一个数组，数组的元素是NSrange，根据NSRange来进行截取字符串
 */
- (NSArray *)getPagesOfString:(NSString *)cache withFont:(UIFont*)font inRect:(CGRect)r;

@end



@interface NSString (Trims)

/** 清除html标签 */
- (NSString *)stringByStrippingHTML;

/** 清除js脚本 */
- (NSString *)stringByRemovingScriptsAndStrippingHTML;

/** 去除空格 */
- (NSString *)trimmingWhitespace;

/** 去除空格与空行 */
- (NSString *)trimmingWhitespaceAndNewlines;

@end




@interface NSString (MIMEType)
/**  获得文件的MIMEType */
- (NSString *)MIMEType;
- (NSString *)MIMEType2;

@end


