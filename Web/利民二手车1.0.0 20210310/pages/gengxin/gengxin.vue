<template>
	<view>
		<web-view class="sss" :src="link"></web-view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				link:null
			}
		},
		onLoad(in77) {
			console.log(in77.ul)
			this.link = in77.ul
		},
		methods: {
			
		}
	}
</script>

<style>
	.sss{
		width: 100%;
		height: 100%;
	}
</style>
