<template>
	<view>
		<scroll-view class="init" >
			<view class="it" v-for="(item,i) in lists" @click="jinqu(item.uuid)">
				<h1 class="title">{{item.pinpai+" "+item.chexing+" "+item.jiage}}</h1>
				<p class="p2">电话联系</p>
				<p class="p3" v-show="item.zhaopian != 0">有图</p>
				<p class="p4" v-show="item.wx != 0">微信咨询</p>
			</view>
		</scroll-view>
		<view class="fei" @click="hidden()"> <p>+</p> </view>
		<view class="menu" id="menu" v-show="v">
			<div class="b1" @click="fabu()"><p>发布</p></div>
			<div class="b1" @click="sousuo()"><p>搜索</p></div>
			<div class="b1" @click="guanyu()"><p>关于</p></div>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				title: 'Hello',
				v: false,
				clientid: '',
				lists: null,
				lister:null
			}
		},
		onLoad() {
					var that = this;
					//获取客户端ID和版本号
					// #ifdef APP-PLUS
					// 苹果系统
					plus.device.getInfo({
						success: function(e) {
							this.clientid = e.uuid;
							uni.setStorageSync('clientid', this.clientid);
						},
						fail: function(e) {
							console.log(e);
						}
					});
					// 安卓系统
					plus.device.getAAID({
						success: function(e) {
							this.clientid = e.aaid;
							console.log(this.clientid);
							uni.setStorageSync('clientid', this.clientid);
						},
						fail: function(e) {
							console.log(e);
						}
					});
					//老版本、安卓模拟器
					if (this.clientid == '') {
						this.clientid = plus.device.uuid;
						uni.setStorageSync('clientid', this.clientid);
					}
					// #endif
					
					uni.request({
						url:"http://3697c2a501.imdo.co/cars?uuid=123"+this.clientid,
						success(data) {
							that.lists = data.data;
						},
						fail(s) {
							uni.showToast({
								title:"服务器连接超时",
								icon:"none"
							});
						}
					});
					uni.request({
						url:"http://3697c2a501.imdo.co/azaz",
						success(data) {
							if(data.data[1] != "1.0.0"){
								uni.showToast({
									title:"监测到版本更新",
									icon:"none"
								});
								uni.navigateTo({
									url:"../gengxin/gengxin?ul="+data.data[2]
								}) 
							}
						},
						fail(s) {
							uni.showToast({
								title:"服务器连接超时",
								icon:"none"
							});
						}
					});
		},
		onPullDownRefresh() {
			var that = this;
			uni.request({
				url:"http://3697c2a501.imdo.co/cars?uuid=123"+this.clientid,
				success(data) {
					that.lists = data.data;
				},
				fail(s) {
					uni.showToast({
						title:"服务器连接超时",
						icon:"none"
					});
				}
			});
			uni.request({
				url:"http://3697c2a501.imdo.co/azaz",
				success(data) {
					if(data.data[1] != "1.0.0"){
						uni.showToast({
							title:"监测到版本更新",
							icon:"none"
						});
						uni.navigateTo({
							url:"../gengxin/gengxin?ul="+data.data[2]
						}) 
					}
				},
				fail(s) {
					uni.showToast({
						title:"服务器连接超时",
						icon:"none"
					});
				}
			});
			uni.stopPullDownRefresh();
		},
		onReachBottom() {
			var that = this;
			uni.request({
				url:"http://3697c2a501.imdo.co/cars?uuid=123"+this.clientid,
				success(data) {
					that.lister = data.data;
					that.lists = that.lists.concat(that.lister)
				},
				fail(s) {
					uni.showToast({
						title:"服务器连接超时",
						icon:"none"
					});
				}
			});
		},
		methods: {
			hidden() {
				if(this.v == true){
					this.v = false;
				}
				else{
					this.v = true;
				} 
			},
			yin() {
				this.v = false;
			},
			fabu() {
				uni.navigateTo({
					url:"../fabu/fabu?id="+"6677"+this.clientid
				});
			},
			guanyu() {
				uni.navigateTo({
					url:"../guanyu/guanyu"
				});
			},
			jinqu(uuid) {
				uni.navigateTo({
					url:"../neirong/neirong?uuid="+uuid
				});	
					this.v = false;
			},
			sousuo(){
				uni.navigateTo({
					url:"../sousuo/sousuo"
				});
			}
		}
	}
</script>

<style>
	.init{
		background-color: #555555;
	}
	.it{
		position: relative;
		width: 100%;
		height:160rpx;
		background-color: #FFFFFF;
		margin-bottom: 2rpx;
	}
	.title{
		position: absolute;
		left:15rpx;
		top:20rpx;
		max-width: 750rpx;
		overflow: hidden;
		text-overflow: ellipsis;
		white-space: initial;
	}
	.p2{
		position: absolute;
		left:25rpx;
		top:100rpx;
	}
	.p3{
		position: absolute;
		left:175rpx;
		top:100rpx;
		color: red;
	}
	.p4{
		position: absolute;
		left:265rpx;
		top:100rpx;
		color: green;
	}
	.fei{
		position:fixed;
		left:5rpx;
		top:1150rpx;
		height: 110rpx;
		width: 110rpx;
		background-color: green;
		border-radius: 50%;
	}
	.fei p{
		font-size: 100rpx;
		line-height: 95rpx;
		text-align: center;
	}
	.menu{
		position:fixed;
		left:120rpx;
		top:920rpx;
		height: 300rpx;
		width: 251rpx;
		background:transparent;
		border-radius: 10rpx;
	}
	.b1{
		height: 95rpx;
		width: 90%;
		margin-left: 12rpx;
		margin-top: 5rpx;
		margin-bottom: 5rpx;
		background-color: #333333;
		border-radius: 15rpx;
	}
	.b1{
		line-height:95rpx;
		text-align: center;
		color:#FFFFFF;
		font-size: 50rpx;
	}
</style>
