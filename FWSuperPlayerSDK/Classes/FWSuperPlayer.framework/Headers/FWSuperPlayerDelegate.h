//
//  FWSuperPlayerDelegate.h
//  FWSuperPlayer
//
//  Created by SailorGa on 2021/8/13.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#ifndef FWSuperPlayerDelegate_h
#define FWSuperPlayerDelegate_h

#import <Foundation/Foundation.h>

@protocol FWSuperPlayerDelegate <NSObject>

@optional

/// 视频开始播放事件
/// @param isLive 是否是直播流
- (void)onStartPlayingEvent:(BOOL)isLive;

/// 视频结束播放事件
/// @param isLive 是否是直播流
- (void)onStopPlayingEvent:(BOOL)isLive;

/// 视频播放Loading事件
/// @param isLive 是否是直播流
- (void)onLoadingShowEvent:(BOOL)isLive;

/// 视频播放Loading结束事件
/// @param isLive 是否是直播流
- (void)onLoadingEndEvent:(BOOL)isLive;

/// 网络断连事件，且经多次重连抢救无效，更多重试请自行重启播放
/// @param isLive 是否是直播流
- (void)onDisconnectEvent:(BOOL)isLive;

/// 直播 - 切流结果回调
/// @param result YES-切流成功 NO-切流失败
- (void)onLiveStreamSwitch:(BOOL)result;

/// 点播 - 视频播放进度回调
/// @param progress 当前播放时间
/// @param duration 总时长
- (void)onPlayingWithProgress:(CGFloat)progress duration:(CGFloat)duration;

@end

#endif /* FWSuperPlayerDelegate_h */
