//
//  UIControl+Tool.m
//  ToolKits
//
//  Created by WuChunlong on 2017/2/20.
//  Copyright © 2017年 WuChunlong. All rights reserved.
//

#import "UIControl+Tool.h"

@implementation UIControl (Tool)

@end


#import <objc/runtime.h>

@implementation UIControl (Delay)

+ (void)load
{
    Method a = class_getInstanceMethod(self, @selector(sendAction:to:forEvent:));
    Method b = class_getInstanceMethod(self, @selector(WCL_sendAction:to:forEvent:));
    
    method_exchangeImplementations(a, b);
}

- (NSTimeInterval)acceptEventInterval
{
    return [objc_getAssociatedObject(self, @selector(acceptEventInterval)) doubleValue];
}

- (void)setAcceptEventInterval:(NSTimeInterval)acceptEventInterval
{
    objc_setAssociatedObject(self, @selector(acceptEventInterval), @(acceptEventInterval), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)WCL_sendAction:(SEL)action to:(id)target forEvent:(UIEvent *)event
{
    [self WCL_sendAction:action to:target forEvent:event];
    
    self.userInteractionEnabled = NO;
    
    //第一种
    //[self performSelector:@selector(setUserInteractionEnabled:) withObject:@(YES) afterDelay:self.acceptEventInterval];
    
    //第二种
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(self.acceptEventInterval * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self.userInteractionEnabled = YES;
    });
}

@end
