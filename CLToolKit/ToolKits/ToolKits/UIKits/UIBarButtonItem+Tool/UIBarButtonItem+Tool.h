//
//  UIBarButtonItem+Tool.h
//  ToolKits
//
//  Created by WuChunlong on 2017/2/20.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (Tool)

@end


@interface UIBarButtonItem (Badge)

@property (strong, atomic) UILabel *badge;

/** badge的文字 */
@property (nonatomic) NSString *badgeValue;

/** 背景颜色 */
@property (nonatomic) UIColor *badgeBGColor;

/** 文字颜色 */
@property (nonatomic) UIColor *badgeTextColor;

/** 文字的字体 */
@property (nonatomic) UIFont *badgeFont;

/** badge的padding */
@property (nonatomic) CGFloat badgePadding;

/** 最小的size */
@property (nonatomic) CGFloat badgeMinSize;

/** x坐标 */
@property (nonatomic) CGFloat badgeOriginX;

/** y坐标 */
@property (nonatomic) CGFloat badgeOriginY;

/** 如果是数字0的话就隐藏不显示 */
@property BOOL shouldHideBadgeAtZero;

/** 是否要缩放动画 */
@property BOOL shouldAnimateBadge;

@end



@interface UIBarButtonItem (Extension)
+ (instancetype)itemWithImage:(NSString *)image highImage:(NSString *)highImage target:(id)target action:(SEL)action;
@end
