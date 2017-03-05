//
//  UIColor+Tool.h
//  MyToolBox
//
//  Created by Wu on 2017/2/17.
//  Copyright © 2017年 Wu. All rights reserved.
//
//  UIColor+YYAdd.h
//  YYKit <https://github.com/ibireme/YYKit>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Tool)

#pragma mark - Create a UIColor Object
/*
 Create UIColor with a hex string.
 Example: UIColorHex(0xF0F), UIColorHex(66ccff), UIColorHex(#66CCFF88)
 
 Valid format: #RGB #RGBA #RRGGBB #RRGGBBAA 0xRGB ...
 The `#` or "0x" sign is not required.
 */
#ifndef WCL_ColorHex
#define WCL_ColorHex(_hex_)   [UIColor colorWithHexString:((__bridge NSString *)CFSTR(#_hex_))]
#endif
// eg: UIColorHex(7D7D7D)

@end

NS_ASSUME_NONNULL_END


@interface UIColor (HexColors)
/** 用十六进制颜色生成UIColor */
+(UIColor *)colorWithHexString:(NSString *)hexString;
+ (UIColor *)colorWithHexString:(NSString *)hexString andAlpha:(CGFloat )alpha;
+(NSString *)hexValuesFromUIColor:(UIColor *)color;

@end


/** 生成一个渐变色*/
@interface UIColor (Gradient)
/**
 *  @brief  渐变颜色
 *
 *  @param fromColor  开始颜色
 *  @param toColor    结束颜色
 *  @param height     渐变高度
 *
 *  @return 渐变颜色
 */
+ (UIColor*)gradientFromColor:(UIColor*)fromColor toColor:(UIColor*)toColor withHeight:(CGFloat)height;

@end

@interface UIColor (HexString)

+ (UIColor *)colorWithHex:(NSString *)stringToConvert;

@end

@interface UIColor (PublicTool)

/** 16进制颜色代码(不须`0x`或`#`前缀) 转UIColor */
+ (UIColor *)colorWithString:(NSString *)hexColor;

/** 输入 0~255 的RGB数值和 0~1 的alpha值 转化UIColor  */
+ (UIColor *)colorWithR:(CGFloat)red G:(CGFloat)green B:(CGFloat)blue alpha:(CGFloat)alpha;

/** 得到一个透明度为 alpha 的随机颜色 */
+ (UIColor *)randomColorWithAlpha:(CGFloat)alpha;
/** 得到一个 alpha 值为 1.0f 的随机颜色 */
+ (UIColor *)randomColor;

@end
