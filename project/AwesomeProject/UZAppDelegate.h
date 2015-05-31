//
//  UZAppDelegate.h
//  UZEngine
//
//  Created by broad on 14-1-13.
//  Copyright (c) 2014年 APICloud. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UZAppDelegate : UIResponder
<UIApplicationDelegate>

@property (readonly, strong, nonatomic) NSMutableArray *widgetControllers;
@property (readonly, strong, nonatomic) NSMutableDictionary *appHandleDict;     //即将废弃，使用addAppHandle: 方法代替
@property (atomic) BOOL UZIsBusy;

/**
 获取主widget的config.xml里面所有模块配置信息
 
 @return 模块配置信息列表
 */
- (NSArray *)features;

/**
 获取主widget的config.xml里面指定模块配置信息
 
 @return 模块配置信息
 */
- (NSDictionary *)getFeatureByName:(NSString *)name;

//实现UIApplicationDelegate方法来接收应用消息，例如推送
- (void)addAppHandle:(id <UIApplicationDelegate>)handle;
- (void)removeAppHandle:(id <UIApplicationDelegate>)handle;

/**
 接收到推送消息后，可以在状态栏显示该条消息，用户点击后，前端页面可以通过监听事件得到消息附加内容
 
 @param msg 显示的内容
 
 @param extra 附加内容，不会显示
 
 @param duration 显示的时长，为0时直到用户点击后才消失
 */
- (void)showMsgOnStatusBar:(NSString *)msg extra:(id)extra duration:(NSTimeInterval)duration;

//在模块配置的启动方法里面调用该方法，可以添加自定义启动画面
- (void)addCustomLaunchView:(UIView *)view;

//移除启动画面
- (void)removeLaunchView;

@end

#define theApp ((UZAppDelegate *)[[UIApplication sharedApplication] delegate])
