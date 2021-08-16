//
//  FWSuperLivePlayer.h
//  FWSuperPlayer
//
//  Created by SailorGa on 2021/8/13.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <FWSuperPlayer/FWSuperPlayerEnum.h>
#import <FWSuperPlayer/FWSuperPlayerDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface FWSuperLivePlayer : NSObject

/// 事件回调
@property(nonatomic, weak) id <FWSuperPlayerDelegate> delegate;

/// 是否开启硬件加速，默认值：NO
@property (nonatomic, assign) BOOL enableHWAcceleration;


#pragma mark - 播放基础接口
/// 创建 Video 渲染 View，该控件承载着视频内容的展示。
/// @param view 父 view
/// @param idx  Widget 在父 view 上 的层级位置
- (void)setupVideoWidget:(UIView *)view insertIndex:(unsigned int)idx;

/// 移除 Video 渲染 Widget
- (void)removeVideoWidget;

/// 启动从指定 URL 播放 RTMP 音视频流
/// @param url 完整的 URL（如果播放的是本地视频文件，这里传本地视频文件的完整路径）
/// 0表示成功，其它为失败
- (int)startPlay:(NSString *)url;

/// 停止播放音视频流
/// 0：成功；其它：失败
- (int)stopPlay;

/// 是否正在播放
/// YES 拉流中，NO 没有拉流
- (BOOL)isPlaying;

/// 暂停播放
/// 适用于点播，直播（此接口会暂停数据拉流，不会销毁播放器，暂停后，播放器会显示最后一帧数据图像）
- (void)pause;

/// 继续播放
/// 适用于点播，直播
- (void)resume;

/// 设置播放速率
/// @param rate rate 正常速度为1.0；小于为慢速；大于为快速。最大建议不超过2.0
- (void)setRate:(float)rate;

/// 播放跳转到音视频流某个时间
/// @param time 流时间，单位为秒
/// 0：成功；其它：失败
- (int)seek:(float)time;


#pragma mark - 视频相关接口
/// 设置画面的方向
/// @param rotation 方向
- (void)setRenderRotation:(FWHomeOrientationType)rotation;

/// 设置画面的裁剪模式
/// @param renderMode 裁剪
- (void)setRenderMode:(FWRenderModeType)renderMode;

/// 截屏
/// @param snapshotCompletionBlock  通过回调返回当前图像
- (void)snapshot:(void (^)(UIImage *image))snapshotCompletionBlock;

/// 获取当前渲染帧 pts
/// 0：当前未处于正在播放状态（例如：未起播）
/// >0：当前渲染视频帧的 pts，处于正在播放状态 (单位: 毫秒)
- (uint64_t)getCurrentRenderPts;


#pragma mark - 音频相关接口
/// 设置静音
/// @param enable 开关
- (void)setMute:(BOOL)enable;

/// 设置音量
/// @param volume 音量大小，取值范围0 - 100
- (void)setVolume:(int)volume;

/// 设置声音播放模式（切换扬声器，听筒）
/// @param audioRoute 声音播放模式
+ (void)setAudioRoute:(FWAudioRouteType)audioRoute;

/// 设置音量大小回调接口
/// @param volumeEvaluationListener 音量大小回调接口，音量取值范围0 - 100
- (void)setAudioVolumeEvaluationListener:(void(^)(int volume))volumeEvaluationListener;

/// 启用音量大小提示
/// @param interval 决定了 volumeEvaluationListener
/// 开启后会在 volumeEvaluationListener 中获取到 SDK 对音量大小值的评估。
/// 回调的触发间隔，单位为ms，最小间隔为100ms，如果小于等于0则会关闭回调，建议设置为300ms；
- (void)enableAudioVolumeEvaluation:(NSUInteger)interval;


#pragma mark - 更多实用接口
/// 设置状态浮层 view 在渲染 view 上的边距
/// @param margin 边距
- (void)setLogViewMargin:(UIEdgeInsets)margin;

/// 是否显示播放状态统计及事件消息浮层 view
/// @param isShow 是否显示
- (void)showVideoDebugLog:(BOOL)isShow;

/// FLV 直播无缝切换
/// @param playUrl 播放地址
/// 0：成功；其它：失败
- (int)switchStream:(NSString *)playUrl;

/// 调用实验性 API 接口
/// @param jsonStr 接口及参数描述的 JSON 字符串
- (void)callExperimentalAPI:(NSString *)jsonStr;

@end

NS_ASSUME_NONNULL_END
