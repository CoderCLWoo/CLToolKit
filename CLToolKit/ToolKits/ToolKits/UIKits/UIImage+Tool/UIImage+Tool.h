//
//  UIImage+Tool.h
//  MyToolBox
//
//  Created by Wu on 2017/2/17.
//  Copyright © 2017年 Wu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Tool)

/** 根据当前图像和指定尺寸进行裁切，生成圆角图像，并返回 */
//- (UIImage *)cornerImageWithSize:(CGSize)size; // 此种方法圆角图像周边会变成黑色
/** 根据当前图像和指定尺寸进行裁切，生成圆角图像，并设置周边填充颜色后返回 */
- (UIImage *)cornerImageWithSize:(CGSize)size fillColor:(UIColor *)fillColor;
/** 异步执行裁切圆角图像完成后，通过block参数回调通知调用方结果 */
- (void)cornerImageWithSize:(CGSize)size fillColor:(UIColor *)fillColor completion:(void(^)(UIImage *image))completion;  // 推荐使用：性能最好！

@end


@interface UIImage (Fit)

/**
 *  传入图片名称,返回拉伸好的图片
 */
+ (UIImage *)resizeImage:(NSString *)imageName;

@end


@interface UIImage (Color)

/**
 根据指定的颜色生成一张指定大小的纯色图片
 
 @param color 颜色
 @param size 大小
 @return 一张图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

/** 根据颜色生成纯色图片 */
+ (UIImage *)imageWithColor:(UIColor *)color;

/** 取图片某一像素的颜色 */
- (UIColor *)colorAtPixel:(CGPoint)point;

/** 获得灰度图 */
- (UIImage *)convertToGrayImage;

@end



//https://github.com/CompletionHandler/CYImageCompress
@interface UIImage (Extension)

/** 压缩图片: 最大字节大小为maxLength */
- (NSData *)compressWithMaxLength:(NSInteger)maxLength;

@end


//https://github.com/nicklockwood/FXImageView
@interface UIImage (FXImage)
/** 裁剪到指定尺寸 */
- (UIImage *)imageCroppedToRect:(CGRect)rect;
/** 缩放到指定大小 */
- (UIImage *)imageScaledToSize:(CGSize)size;
- (UIImage *)imageScaledToFitSize:(CGSize)size;
- (UIImage *)imageScaledToFillSize:(CGSize)size;
- (UIImage *)imageCroppedAndScaledToSize:(CGSize)size
                             contentMode:(UIViewContentMode)contentMode
                                padToFit:(BOOL)padToFit;

- (UIImage *)reflectedImageWithScale:(CGFloat)scale;
- (UIImage *)imageWithReflectionWithScale:(CGFloat)scale gap:(CGFloat)gap alpha:(CGFloat)alpha;
- (UIImage *)imageWithShadowColor:(UIColor *)color offset:(CGSize)offset blur:(CGFloat)blur;
- (UIImage *)imageWithCornerRadius:(CGFloat)radius;
- (UIImage *)imageWithAlpha:(CGFloat)alpha;
- (UIImage *)imageWithMask:(UIImage *)maskImage;

- (UIImage *)maskImageFromImageAlpha;


@end


@interface UIImage (Gif)

/** 用一个Gif生成UIImage，传入一个GIFData */
+ (UIImage *)animatedImageWithAnimatedGIFData:(NSData *)theData;

/** 用一个Gif生成UIImage，传入一个GIF路径 */
+ (UIImage *)animatedImageWithAnimatedGIFURL:(NSURL *)theURL;

@end



//https://github.com/AYastrebov/UIImage-RemoteSize
@interface UIImage (RemoteSize)

typedef void (^UIImageSizeRequestCompleted) (NSURL* imgURL, CGSize size);

/** 请求远端图片的size */
+ (void)requestSizeFor:(NSURL*)imgURL completion:(UIImageSizeRequestCompleted)completion;

@end




@interface UIImage (Rotate)

/** 纠正图片的方向 */
- (UIImage *)fixOrientation;

/** 按给定的方向旋转图片 */
- (UIImage*)rotate:(UIImageOrientation)orient;

/** 垂直翻转 */
- (UIImage *)flipVertical;

/** 水平翻转 */
- (UIImage *)flipHorizontal;

/** 将图片旋转degrees角度 */
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;

/** 将图片旋转radians弧度 */
- (UIImage *)imageRotatedByRadians:(CGFloat)radians;

@end



@interface UIImage (SubImage)

/** 截取当前image对象rect区域内的图像 */
- (UIImage *)subImageWithRect:(CGRect)rect;

/** 压缩图片至指定尺寸 */
- (UIImage *)rescaleImageToSize:(CGSize)size;

/** 压缩图片至指定像素 */
- (UIImage *)rescaleImageToPX:(CGFloat )toPX;

/** 在指定的size里面生成一个平铺的图片 */
- (UIImage *)getTiledImageWithSize:(CGSize)size;

/** UIView转化为UIImage */
+ (UIImage *)imageFromView:(UIView *)view;

/** 将两个图片生成一张图片 */
+ (UIImage*)mergeImage:(UIImage*)firstImage withImage:(UIImage*)secondImage;

@end


@interface UIImage (OrientationFix)

- (UIImage *)imageWithFixedOrientation;

@end


