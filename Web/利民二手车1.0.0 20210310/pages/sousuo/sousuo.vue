<template>
	<view>
		<p class="jia">价格区间</p>
		
		<picker @change="jiages" class="jiage" :range="jiage" >
			<label>{{jiage[jiage2]}}</label>
			<label class="btt">∨</label>
		</picker><br/>
		<scroll-view>
			<view class="it" v-for="(item,i) in lists" @click="jinqu(item.uuid)">
				<h1 class="title">{{item.pinpai+" "+item.chexing+" "+item.jiage}}</h1>
				<p class="p2">电话联系</p>
				<p class="p3" v-show="item.zhaopian != 0">有图</p>
				<p class="p4" v-show="item.wx != 0">微信咨询</p>
			</view>
		</scroll-view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				jiage: ["价格","1万元以下","2~3万元","4~8万元","9~11万元","12万元~30万元","31万元~40万元","41万元~50万元","51万元~60万元","61万元~70万元","71万元~80万元","80万元以上"],
				jiage1: 'null',
				jiage2: 0,
				lists: []
			}
		},
		methods: {
			jiages(e) {
				var that = this;
				this.jiage2 = e.target.value;
				this.jiage1 = this.jiage[this.jiage2];
				uni.request({
					url:"http://3697c2a501.imdo.co/search?jiage="+this.jiage1,
					success(data) {
						that.lists = data.data;
					}
				})
			},
			jinqu(uuid) {
				uni.navigateTo({
					url:"../neirong/neirong?uuid="+uuid
				});	
					this.v = false;
			}
		}
	}
</script>

<style>
	.jia{
		display:inline-block;
		margin-top: 18rpx;
	}
	.jiage{
		display:inline-block;
		height:50rpx;
		width: 300rpx;
		margin-left: 15rpx;
		border: 2rpx solid #333333;
	}
	.btt{
		float: right;
		margin-right: 10rpx;
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
</style>
