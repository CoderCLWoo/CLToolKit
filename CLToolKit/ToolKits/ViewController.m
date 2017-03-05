//
//  ViewController.m
//  ToolKits
//
//  Created by WuChunlong on 2017/2/19.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import "ViewController.h"

#import "ToolKits.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    NSLog(@"hello world");

}


//< 生成圆角图片.
- (void)getCornerImage {
    UIImage *img = [UIImage imageWithColor:[UIColor cyanColor] size:CGSizeMake(800, 800)];
    UIImageView *iv = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 200, 200)];
    iv.center = self.view.center;
    [self.view addSubview: iv];
    
    
    // 方法1：设置cornerRadius ，性能最差
//    iv.image = img;
//    iv.layer.cornerRadius = 100;
//    iv.layer.masksToBounds = YES;
    
    // 方法2：利用绘图，性能提高
//    iv.image = [img cornerImageWithSize:iv.bounds.size];
//    iv.image = [img cornerImageWithSize:iv.bounds.size fillColor:[UIColor whiteColor]];
    [img cornerImageWithSize:iv.bounds.size fillColor:[UIColor whiteColor] completion:^(UIImage *image) {
        iv.image = image;
    }];
    
    
    
}

- (void)test1 {
    self.view.backgroundColor = WCL_ColorHex(123456);
    UIView *v = [[UIView alloc] initWithFrame:CGRectMake(120, 120, 150, 60)];
    v.backgroundColor = WCL_ColorHex(7d7d7d);
    [self.view addSubview:v];
    [v.layer shakeWithAmplitude:16 direction:CALayerShakeDirectionHorizontal];
    
    UIButton *btn = [[UIButton alloc] initWithFrame:CGRectMake(120, 200, 150, 80)];
    btn.backgroundColor = WCL_ColorHex(666666);
    btn.badgeValue = @"8";
    [self.view addSubview:btn];

}

@end
