//
//  FWSuperVodPlayer.h
//  FWSuperPlayer
//
//  Created by SailorGa on 2021/8/13.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <FWSuperPlayer/FWSuperPlayerEnum.h>
#import <FWSuperPlayer/FWSuperPlayerDelegate.h>
#import <FWSuperPlayer/FWSuperPlayerBitrateItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface FWSuperVodPlayer : NSObject

/// 事件回调
@property(nonatomic, weak) id <FWSuperPlayerDelegate> delegate;

/// 是否开启硬件加速
/// 播放前设置有效
@property(nonatomic, assign) BOOL enableHWAcceleration;

/// startPlay后是否立即播放，默认YES
@property (nonatomic) BOOL isAutoPlay;

/// 加密HLS的token。设置此值后，播放器自动在URL中的文件名之前增加 voddrm.token.TOKEN
@property (nonatomic, strong) NSString *token;

/// 是否循环播放
@property (nonatomic, assign) BOOL loop;

/// 创建Video渲染View,该控件承载着视频内容的展示。
/// @param view 父view
/// @param idx Widget在父view上的层级位置
- (void)setupVideoWidget:(UIView *)view insertIndex:(unsigned int)idx;

/// 移除Video渲染View
- (void)removeVideoWidget;

/// 设置播放开始时间
/// 在startPlay前设置，修改开始播放的起始位置
- (void)setStartTime:(CGFloat)startTime;

/// startPlay 启动从指定URL播放
/// @param url 完整的URL(如果播放的是本地视频文件，这里传本地视频文件的完整路径)
/// 0 = OK
- (int)startPlay:(NSString *)url;

/// 停止播放音视频流
/// @return 0 = OK
- (int)stopPlay;

/// 是否正在播放
- (bool)isPlaying;

/// 暂停播放
- (void)pause;

/// 继续播放
- (void)resume;

/// 播放跳转到音视频流某个时间
/// @param time 流时间，单位为秒
/// 0 = OK
- (int)seek:(float)time;

/// 获取当前播放时间
- (float)currentPlaybackTime;

/// 获取视频总时长
- (float)duration;

/// 可播放时长
- (float)playableDuration;

/// 视频宽度
- (int)width;

/// 视频高度
- (int)height;

/// 设置画面的方向
/// @param rotation 方向
- (void)setRenderRotation:(FWHomeOrientationType)rotation;

/// 设置画面的裁剪模式
/// @param renderMode 裁剪
- (void)setRenderMode:(FWRenderModeType)renderMode;

/// 设置静音
- (void)setMute:(BOOL)bEnable;

/// 设置音量大小
/// @param volume 音量大小。范围：0 ~ 100。
- (void)setAudioPlayoutVolume:(int)volume;

/// 截屏
/// @param snapshotCompletionBlock 通过回调返回当前图像
- (void)snapshot:(void (^)(UIImage *image))snapshotCompletionBlock;

/// 设置播放速率
/// @param rate 正常速度为1.0；小于为慢速；大于为快速。最大建议不超过2.0
- (void)setRate:(float)rate;

/// 当播放地址为master playlist，返回支持的码率（清晰度）
/// 在收到EVENT_VIDEO_PLAY_BEGIN事件后才能正确返回结果
/// 无多码率返回空数组
- (NSArray<FWSuperPlayerBitrateItem *> *)supportedBitrates;

/// 获取当前正在播放的码率索引
- (NSInteger)bitrateIndex;

/// 设置当前正在播放的码率索引，无缝切换清晰度
/// @param index 码率索引，index == -1，表示开启HLS码流自适应；index > 0 （可从supportedBitrates获取），表示手动切换到对应清晰度码率
/// 清晰度切换可能需要等待一小段时间。支持多码率HLS分片对齐，保证最佳体验。
- (void)setBitrateIndex:(NSInteger)index;

/// 设置画面镜像
- (void)setMirror:(BOOL)isMirror;

/// 将当前vodPlayer附着至TRTC
- (void)attachTRTC:(NSObject *)trtcCloud;

/// 将当前vodPlayer和TRTC分离
- (void)detachTRTC;

/// 开始向TRTC发布辅路视频流
- (void)publishVideo;

/// 开始向TRTC发布辅路音频流
- (void)publishAudio;

/// 结束向TRTC发布辅路视频流
- (void)unpublishVideo;

/// 结束向TRTC发布辅路音频流
- (void)unpublishAudio;

@end

NS_ASSUME_NONNULL_END
