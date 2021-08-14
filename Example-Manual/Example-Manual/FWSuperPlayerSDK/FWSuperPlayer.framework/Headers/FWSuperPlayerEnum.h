//
//  FWSuperPlayerEnum.h
//  FWSuperPlayer
//
//  Created by SailorGa on 2021/8/13.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#ifndef FWSuperPlayerEnum_h
#define FWSuperPlayerEnum_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#pragma mark - 画面旋转方向
/// 画面旋转方向
typedef NS_ENUM(NSInteger, FWHomeOrientationType) {
    
    FW_HOME_ORIENTATION_RIGHT     = 0,    /// HOME 键在右边，横屏模式
    FW_HOME_ORIENTATION_DOWN      = 1,    /// HOME 键在下面，手机直播中最常见的竖屏直播模式
    FW_HOME_ORIENTATION_LEFT      = 2,    /// HOME 键在左边，横屏模式
    FW_HOME_ORIENTATION_UP        = 3,    /// HOME 键在上边，竖屏直播（适合小米 MIX2）
};


#pragma mark - 画面填充模式
/// 画面填充模式
typedef NS_ENUM(NSInteger, FWRenderModeType) {
    
    FW_RENDER_MODE_FILL_SCREEN    = 0,    /// 图像铺满屏幕，不留黑边，如果图像宽高比不同于屏幕宽高比，部分画面内容会被裁剪掉。
    FW_RENDER_MODE_FILL_EDGE      = 1,    /// 图像适应屏幕，保持画面完整，但如果图像宽高比不同于屏幕宽高比，会有黑边的存在。
};


#pragma mark - 声音播放模式（音频路由）
/// 声音播放模式（音频路由）
/// 一般手机都有两个扬声器，设置音频路由的作用就是要决定声音从哪个扬声器播放出来。
/// - Speakerphone：扬声器，位于手机底部，声音偏大，适合外放音乐。
/// - Earpiece：听筒，位于手机顶部，声音偏小，适合通话。
typedef NS_ENUM(NSInteger, FWAudioRouteType) {
    
    FW_AUDIO_ROUTE_SPEAKER          = 0,      /// 扬声器，位于手机底部，声音偏大，适合外放音乐。
    FW_AUDIO_ROUTE_RECEIVER         = 1,      /// 听筒，位于手机顶部，声音偏小，适合通话。
};

#endif /* FWSuperPlayerEnum_h */
