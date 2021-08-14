//
//  FWSuperPlayerBitrateItem.h
//  FWSuperPlayer
//
//  Created by SailorGa on 2021/8/13.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// HLS多码率信息
@interface FWSuperPlayerBitrateItem : NSObject

/// m3u8 文件中的序号
@property (nonatomic, assign) NSInteger index;
/// 此流的视频宽度
@property (nonatomic, assign) NSInteger width;
/// 此流的视频高度
@property (nonatomic, assign) NSInteger height;
/// 此流的视频码率
@property (nonatomic, assign) NSInteger bitrate;

@end

NS_ASSUME_NONNULL_END
