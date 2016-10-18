//
//  MACTableView.h
//  WeSchoolTeacher
//
//  Created by MacKun on 16/3/1.
//  Copyright © 2016年 solloun. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef NS_ENUM(NSInteger, MACRefreshState) {

    /** 下拉刷新的状态 */
    MACRefreshing,
    /** pull 加载更多刷新中的状态 */
    MACPulling,
};

typedef NS_ENUM(NSInteger,MACCanLoadState){
    /**不支持下拉和加载更多*/
    MACCanLoadNone,
    /**只支持下拉刷新*/
    MACCanLoadRefresh,
    /** 同时支持下拉和加载更多*/
    MACCanLoadAll,
};

@protocol MACTableViewDelegate <NSObject>

@optional

/**@param state MACRefreshing 下拉刷新 MACPulling 为 Pull 加载更多*/
-(void)loadDataRefreshOrPull:(MACRefreshState)state;

@end

@interface MACTableView : UITableView

@property (nonatomic,weak) id<MACTableViewDelegate> macTableViewDelegate;//MACTableView delegate

/** 是否展示空白页 默认为YES*/
@property(nonatomic,assign,getter = isShowEmpty)BOOL showEmpty;
/** MACTableView 加载支持，默认同时支持下拉和加载更多*/
@property (nonatomic,assign) IBInspectable MACCanLoadState macCanLoadState;
/**空白页的标题 默认为 “" 为空,不显示*/
@property(nonatomic,copy) IBInspectable NSString *emptyTitle;
/**  空白页的副标题 默认为 “" 为空,不显示*/
@property(nonatomic,copy) IBInspectable NSString *emptySubtitle;
/**  空白页展位图名称 默认为 nil,不显示*/
@property(nonatomic,strong) IBInspectable UIImage *emptyImage;
/**  空白页背景颜色,默认白色*/
@property(nonatomic,strong) IBInspectable UIColor *emptyColor;

/** 获取当下访问接口Page下标 默认从1开始 以来代替控制器计算Page*/
-(NSNumber *)getCurrentPage;
/** 开始加载*/
-(void)beginLoading;
/**结束加载，并刷新数据*/
-(void)endLoading;
/**提示无更多数据*/
-(void)noMoreData;
@end
