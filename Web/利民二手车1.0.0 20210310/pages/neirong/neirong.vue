<template>
	<view>
		<h1 class="title">详细信息</h1>
		<p>{{"品牌:"+list[0].pinpai}}</p>
		<p>{{"车型:"+list[0].chexing}}</p>
		<p>{{"出场年月:"+list[0].nian+"年"+list[0].yue}}</p>
		<p>{{"户籍:"+list[0].huji}}</p>
		<p>{{"价格范围:"+list[0].jiage}}</p>
		<p @click="dianhua()">电话:{{dianhua1}}</p>
		<p v-show="list[0].wx != 0">可加微信</p>
		<image class="tp" v-show="list[0].zhaopian != 0" :src="list[0].zhaopian"></image>
		<p v-show="list[0].zhaopian != 0">↑由于网络原因图片可能要几分钟时间显示</p>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				uuid:null,
				list:null,
				dianhua1:'点击查看'
			}
		},
		onLoad(thing) {
			var that = this
			console.log(thing.uuid)
			this.uuid=thing.uuid
			uni.request({
				url:"http://3697c2a501.imdo.co/car?uuid="+this.uuid,
				success(data) {
					console.log(data)
					that.list = data.data;
				},
				fail(s) {
					uni.showToast({
						title:"服务器连接超时",
						icon:"none"
					});
				}
			})
		},
		methods: {
			dianhua() {
				console.log(this.list[0].zhaopian)
				this.dianhua1 = this.list[0].dianhua;
			}
		}
	}
</script>

<style>
	.title{
		text-align: center;
	}
	.tp{
		width:750rpx;
		height:500rpx;
	}
</style>
