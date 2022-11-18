<template>
	<view>
		<h1 class="title">我发布的信息</h1>
		<p>{{list[0].pinpai}}</p>
		<p>{{list[0].chexing}}</p>
		<p>{{list[0].huji}}</p>
		<p>{{list[0].dianhua}}</p>
		<p>{{list[0].nian+"年"}}</p>
		<p>{{list[0].yue}}</p>
		<p v-show="list[0].tupian">有图</p>
		<button @click="del()">删除本条信息</button>
		<p>注：主页出售信息内容出现方式是随机的，所以出售信息曝光率是均衡的，在没有卖出前请不要反复删除发送！若被加入黑名单将无法咋发送信息！</p>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				my:'',
				list:null
			}
		},
		onLoad(pr1) {
			var that = this
			this.my=pr1.id
			uni.request({
				url:"http://3697c2a501.imdo.co/car?uuid="+this.my,
				success(data) {
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
			del(){
				uni.request({
					url:"http://3697c2a501.imdo.co/carsan?uuid="+this.my,
					success() {
						uni.showToast({
							title:"删除成功！",
							icon:"none"
						});
						uni.redirectTo({
							url:"../index/index"
						});
					},
					fail(s) {
						uni.showToast({
							title:"服务器连接超时",
							icon:"none"
						});
						uni.redirectTo({
							url:"../index/index"
						});
					}
				})
			}
		}
	}
</script>

<style>
	.title{
		text-align: center;
	}
</style>
