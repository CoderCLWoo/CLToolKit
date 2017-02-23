//
//  UIImageView+Tool.m
//  ToolKits
//
//  Created by Wu on 2017/2/23.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import "UIImageView+Tool.h"
#import "NSObject+Tool.h"

@implementation UIImageView (Tool)

@end


@implementation UIImageView (Extension)

//+ (void)load {
//    method_swizzle(self, @selector(setImage:), @selector(cl_setImage:));
//}

- (void) cl_setImage:(UIImage *)image {
    NSLog(@"方法名：%s, 行号：%d", __PRETTY_FUNCTION__, __LINE__);
    
    
   // 1. 根据imageView的大小，重新调整 image 的大小
    // 使用 `CG` 重新生成一张和目标尺寸相同的图片
    UIGraphicsBeginImageContextWithOptions(self.bounds.size, YES, 0);
    
    // 绘制图像
    [image drawInRect:self.bounds];
    
    // 取得结果
    UIImage *result = UIGraphicsGetImageFromCurrentImageContext();
    
    // 关闭上下文
    UIGraphicsEndImageContext();
    
    
    // 调用系统默认的 setImage 方法
//    [self cl_setImage:result];
    [self setImage:result];
    
    
    NSLog(@"方法名：%s, 行号：%d", __PRETTY_FUNCTION__, __LINE__);
}

@end
