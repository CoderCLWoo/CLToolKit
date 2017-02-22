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

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
