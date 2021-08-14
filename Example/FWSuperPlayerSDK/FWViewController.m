//
//  FWViewController.m
//  FWSuperPlayerSDK
//
//  Created by SailorGa on 08/14/2021.
//  Copyright (c) 2021 SailorGa. All rights reserved.
//

#import "FWViewController.h"
#import <FWSuperPlayer/FWSuperPlayer.h>

@interface FWViewController () <FWSuperPlayerDelegate>

/// 播放器父组件
@property (weak, nonatomic) IBOutlet UIView *playerView;

/// 直播播放器
@property (nonatomic, strong) FWSuperLivePlayer *livePlayer;
/// 点播播放器
@property (nonatomic, strong) FWSuperVodPlayer *vodPlayer;

@end

@implementation FWViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    /// 初始化UI
    [self buildView];
}

#pragma mark - 页面出现前
- (void)viewWillAppear:(BOOL)animated {
    
    [super viewWillAppear:animated];
    /// 隐藏顶部导航栏
    [self.navigationController setNavigationBarHidden:YES animated:YES];
    /// 设置状态栏样式
    [UIApplication sharedApplication].statusBarStyle = UIStatusBarStyleLightContent;
}

#pragma mark - 页面即将消失
- (void)viewWillDisappear:(BOOL)animated {
    
    [super viewWillDisappear:animated];
    /// 显示顶部导航栏
    [self.navigationController setNavigationBarHidden:NO animated:YES];
}

#pragma mark - 懒加载直播播放器
- (FWSuperLivePlayer *)livePlayer {
    
    if (!_livePlayer) {
        _livePlayer = [[FWSuperLivePlayer alloc] init];
        _livePlayer.delegate = self;
    }
    return _livePlayer;
}

#pragma mark - 懒加载点播播放器
- (FWSuperVodPlayer *)vodPlayer {
    
    if (!_vodPlayer) {
        _vodPlayer = [[FWSuperVodPlayer alloc] init];
        _vodPlayer.delegate = self;
        _vodPlayer.loop = YES;
    }
    return _vodPlayer;
}

#pragma mark - 初始化UI
- (void)buildView {
    
    /// 获取SDK版本
    NSLog(@"++++++++++当前SDK版本 = %@", [FWSuperPlayerBase version]);
}

#pragma mark - 结束播放按钮事件
- (IBAction)stopPlayAction:(UIButton *)sender {
    
    /// 停止播放并释放播放器
    [self releasePlayer];
}

#pragma mark - 直播播放按钮事件
- (IBAction)liveStartPlayAction:(UIButton *)sender {
    
    /// 停止播放并释放播放器
    [self releasePlayer];
    /// 点播播放器创建Video渲染View
    [self.livePlayer setupVideoWidget:self.playerView insertIndex:0];
    /// 启动从指定URL播放音视频流
    [self.livePlayer startPlay:@"http://liteavapp.qcloud.com/live/liteavdemoplayerstreamid.flv"];
}

#pragma mark - 点播播放按钮事件
- (IBAction)vodStartPlayAction:(UIButton *)sender {
    
    /// 停止播放并释放播放器
    [self releasePlayer];
    /// 点播播放器创建Video渲染View
    [self.vodPlayer setupVideoWidget:self.playerView insertIndex:0];
    /// 启动从指定URL播放音视频流
    [self.vodPlayer startPlay:@"https://media.w3.org/2010/05/sintel/trailer.mp4"];
}

#pragma mark - 停止播放并释放播放器
/// 停止播放并释放播放器
- (void)releasePlayer {
    
    /// 直播播放器停止播放
    [_livePlayer stopPlay];
    /// 点播播放器移除Video渲染View
    [_livePlayer removeVideoWidget];
    
    /// 点播播放器停止播放
    [_vodPlayer stopPlay];
    /// 点播播放器移除Video渲染View
    [_vodPlayer removeVideoWidget];
    
    /// 置空播放器
    _livePlayer = nil;
    _vodPlayer = nil;
}

#pragma mark - -------------- FWSuperPlayerDelegate的代理方法 ---------------
#pragma mark 视频开始播放事件
/// 视频开始播放事件
/// @param isLive 是否是直播流
- (void)onStartPlayingEvent:(BOOL)isLive {
    
    NSLog(@"++++++++++视频开始播放事件");
}

#pragma mark 视频结束播放事件
/// 视频结束播放事件
/// @param isLive 是否是直播流
- (void)onStopPlayingEvent:(BOOL)isLive {
    
    NSLog(@"++++++++++视频结束播放事件");
}

#pragma mark 视频播放Loading事件
/// 视频播放Loading事件
/// @param isLive 是否是直播流
- (void)onLoadingShowEvent:(BOOL)isLive {
    
    NSLog(@"++++++++++视频播放Loading事件");
}

#pragma mark 视频播放Loading结束事件
/// 视频播放Loading结束事件
/// @param isLive 是否是直播流
- (void)onLoadingEndEvent:(BOOL)isLive {
    
    NSLog(@"++++++++++视频播放Loading结束事件");
}

#pragma mark 网络断连事件，且经多次重连抢救无效，更多重试请自行重启播放
/// 网络断连事件，且经多次重连抢救无效，更多重试请自行重启播放
/// @param isLive 是否是直播流
- (void)onDisconnectEvent:(BOOL)isLive {
    
    NSLog(@"++++++++++网络断连事件，且经多次重连抢救无效，更多重试请自行重启播放");
}

#pragma mark 直播 - 切流结果回调
/// 直播-切流结果回调
/// @param result YES-切流成功 NO-切流失败
- (void)onLiveStreamSwitch:(BOOL)result {
    
    NSLog(@"++++++++++直播-切流结果回调 = %@", result ? @"切流成功" : @"切流失败");
}

#pragma mark 点播 - 视频播放进度回调
/// 点播 - 视频播放进度回调
/// @param progress 当前播放时间
/// @param duration 总时长
- (void)onPlayingWithProgress:(CGFloat)progress duration:(CGFloat)duration {
    
    NSLog(@"++++++++++视频播放进度 duration = %f, progress = %f", duration, progress);
}

@end
