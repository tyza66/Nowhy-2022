<template>
	<view>
		<view class="bk">
			<h1 class="title">关于</h1>
			<p class="lk">软件：洮羱芝闇</p>
			<p class="lk">界面：洮羱芝闇</p>
			<p class="lk">当前版本：1.0.0</p>
			<p class="lk">目前UI尚未进行优化，而且服务器性能有限。</p>
			<p class="lk">我们跟需要您的帮助。</p>
			<p class="lk">我您可以通过以下方式帮助到我们。</p>
			<p class="lk">1. 多点击一些平台上面投放个广告</p>
			<p class="lk">2. 您还可以扫描二维码来赞助我们</p>
			<p class="lk">邮箱：shun_@outlook.com</p>
			<p class="lk">邮箱：1520600496@qq.com</p>
			<view class="b1">
				<p>支付宝</p>
				<image class="zfb" src="../../static/shdf9oawseiuhdioasdfhioasuhdfiousa.png"></image>
			</view>
			<view class="b2">
				<p>微信</p>
				<image class="wx" src="../../static/dsjnkodjshjo.png"></image>
			</view>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				
			}
		},
		methods: {
			
		}
	}
</script>

<style>
	.bk{
		position: fixed;
		width: 100%;
		height: 100%;
		background-color: #008000;
	}
	.title{
		text-align: center;
		margin-top: 25rpx;
	}
	.lk{
		margin-top: 10rpx;
		text-align: center;
	}
	.b1{
		display: inline-block;
		border: 1rpx solid #000000;
		height: 260rpx;
		width: 210rpx;
		margin-left: 162.5rpx;
	}
	.b1 p{
		text-align: center;
	}
	.zfb{
		height: 200rpx;
		width: 200rpx;
		margin-left: 5rpx;
	}
	.b2{
		display: inline-block;
		border: 1rpx solid #000000;
		height: 260rpx;
		width: 210rpx;
		margin-left: 10rpx;
	}
	.b2 p{
		text-align: center;
	}
	.wx{
		height: 200rpx;
		width: 200rpx;
		margin-left: 5rpx;
	}
</style>
