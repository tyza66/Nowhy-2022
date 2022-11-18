<template>
	<view>
		<form class="biao">
			<view class="tpp" v-show="back">
				<view class="info">
					<view class="tishi">提示</view>
					<p>1. 本平台仅提供便民性质的信息交流，请确保您发布的信息真实准确！</p>
					<p>2. 请勿使用本平台发布非法信息！</p>
					<p>3. 由于服务器资源因素，每个用户同时只能上传一条信息，您可以通过取消发布已发布的信息继续发新的信息！</p>
					<p>4. 为了免费平台可持续发展和服务器持续维护，如果您愿意，可以在“首页→关于”中帮助到我们！</p>
					<checkbox-group name="zd" @change="zhidao">
					    <label>  
					        <checkbox value="cb" class="ts1" :checked="isChecked"/><text class="ts2" >我知道了</text>
					    </label>  
					</checkbox-group>
					<button type="primary" @click="queren()" class="queren">确认</button>
				</view>
			</view>
			<h5 class="tit1">请选择您要出售货车的相关信息，并确保信息属实无误！</h5>
			<h5 class="tit2">请勿使用本平台进行非法行为，发布虚假或非法信息！</h5>
			<h5 class="tit3">本平台仅提供信息交流便民之用，不提供交易流程服务！</h5>
			<p class="pin">选择品牌</p>
			<picker @change="pinpais" class="pinpai" :range="pinpai" >
				<label>{{pinpai[pinpai2]}}</label>
				<label class="btt">∨</label>
			</picker><br/>
			
			<p class="chu">出厂日期</p>
			
			<picker @change="nians" class="nian" :range="nian" >
				<label>{{nian[nian2]}}</label>
				<label class="btt">∨</label>
			</picker>
			
			<picker @change="yues" class="yue" :range="yue" >
				<label>{{yue[yue2]}}</label>
				<label class="btt">∨</label>
			</picker><br/>
			
			<p class="che">选择车型</p>
			
			<picker @change="chexings" class="chexing" :range="chexing" >
				<label>{{chexing[chexing2]}}</label>
				<label class="btt">∨</label>
			</picker><br/>
			
			<p class="hu">车辆户籍</p>
			
			<picker @change="hujis" class="huji" :range="huji" >
				<label>{{huji[huji2]}}</label>
				<label class="btt">∨</label>
			</picker><br/>
			
			<p class="jia">价格区间</p>
			
			<picker @change="jiages" class="jiage" :range="jiage" >
				<label>{{jiage[jiage2]}}</label>
				<label class="btt">∨</label>
			</picker><br/>
			
			<p class="dian">联系电话</p>
			
			<input type="number" name="tel" class="diandian" v-model="tel"/><br/>
			
			<checkbox-group name="wx" @change="weixinle">  
			    <label>  
			        <checkbox value="cb" class="wx1" :checked="isChecked1" /><p class="wx2">微信同号</p>
			    </label>  
			</checkbox-group><br/>
			
			<button type="primary" @click="chosseImg()" class="bt1">上传图片</button><button type="primary" @click="clearImg()" class="bt2">清除照片</button>
			
			<view style="height: 355rpx;border: 1rpx solid #333333;">
								<scroll-view  scroll-x="true" 
								@scroll="scroll"  
								style="width: 100%;overflow:hidden;white-space:nowrap;height:355rpx;">
									<view class="scroll-view_H">
										<image mode="scaleToFill" class="tp4" v-for="item in img_url" :src='item' @click="preview(item)" style="height: 355rpx;"></image>
									</view>
								</scroll-view>
							</view>
			
			<br/><p class="ida">识别id:<p class="idb">{{id}}</p></p>
			
			<button type="primary" @click="upload()" class="bt3">提交</button>
			
		</form>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				pinpai:["选择品牌","解放","欧曼","东风","其它"],
				nian: ["出厂年",2005,2006,2007,2008,2009,2010,2011,2012,2013,2014,2015,2016,2017,2018,2019,2020,2021],
				yue: ["出厂月","1月","2月","3月","4月","5月","6月","7月","8月","9月","10月","11月","12月"],
				chexing: ["车型","1.8米车","4.2米车","5.6米车","7.7米车","9.6米车","8.0米车","13.0米车","13.7米车","17.5米车","高栏车","自卸车","冷藏车","其它"],
				huji: ["户籍","辽宁","吉林","黑龙江","河北","山西","陕西","甘肃","青海","山东","安徽","江苏","浙江","河南","湖北","湖南","江西","台湾","福建","云南","海南","四川","贵州","广东","内蒙古","新疆","广西","西藏","宁夏","北京","上海","天津","重庆","香港","澳门"],
				jiage: ["价格","1万元以下","2~3万元","4~8万元","9~11万元","12万元~30万元","31万元~40万元","41万元~50万元","51万元~60万元","61万元~70万元","71万元~80万元","80万元以上"],
				id:'',
				tel:'',
				img_url: '',
				back: true,
				isChecked: false,
				isChecked1: false,
				image666: 'null',
				pinpai1:'null',
				nian1:'null',
				yue1:'null',
				chexing1:'null',
				huji1:'null',
				jiage1:'null',
				pinpai2:0,
				nian2:0,
				yue2:0,
				chexing2:0,
				huji2:0,
				jiage2:0,
				a: 0
			}
		},
		onLoad(thing) {
			this.id = thing.id;
		},
		onShow() {
			
		},
		methods: {
			zhidao(e) {
				//console.log(e.detail.value[0])
				if(e.detail.value[0] == "cb"){
					this.isChecked = true;
				}else{
					this.isChecked = false;
				}
			},
			weixinle(e) {
				//console.log(e.detail.value[0])
				if(e.detail.value[0] == "cb"){
					this.isChecked1 = true;
				}else{
					this.isChecked1 = false;
				}
			},
			pinpais(e) {
				this.pinpai2 = e.target.value;
				this.pinpai1 = this.pinpai[this.pinpai2]
			},
			nians(e) {
				this.nian2 = e.target.value;
				this.nian1 = this.nian[this.nian2]
			},
			yues(e) { 
				this.yue2 = e.target.value;
				this.yue1 = this.yue[this.yue2]
			},
			chexings(e) {
				this.chexing2 = e.target.value;
				this.chexing1 = this.chexing[this.chexing2]
			},
			hujis(e) {
				this.huji2 = e.target.value;
				this.huji1 = this.huji[this.huji2]
			},
			jiages(e) {
				this.jiage2 = e.target.value;
				this.jiage1 = this.jiage[this.jiage2]
			},
			chosseImg() {
						var that = this;
						uni.chooseImage({
							count: 1, 
							success: res => { 
								uni.showToast({
									title:"图片上传中",
									icon:"none"
								});
								this.img_url = res.tempFilePaths 
								 const tempFilePaths = res.tempFilePaths;
								                        const uploadTask = uni.uploadFile({
								                            url: 'http://3697c2a501.imdo.co/cars/picup',
								                            filePath: tempFilePaths[0],
								                            name: 'file',
								                            success: function(uploadFileRes) {
								                                that.image666 = "http://3697c2a501.imdo.co/"+uploadFileRes.data;
																uni.showToast({
																	title:"图片上传成功",
																	icon:"none"
																});
								                            },
															fail:function() {
																uni.showToast({
																	title:"图片上传失败",
																	icon:"none"
																});
																return false;
															}
								                        });
							}
						})
					},
			clearImg() {
				this.img_url='';
			},
			preview(index) {
						uni.previewImage({
							current: index, //当前点击预览的图片
							urls: this.img_url //预览图片的链接
						})
					},
			guanli() {
				uni.navigateTo({
					url:"../guanli/guanli?id="+this.id
				});
			},
			upload(){
				 var reg =/^0?1[3|4|5|6|7|8][0-9]\d{8}$/;
				 var tr = 0;
					if(this.pinpai2 != 0){
						tr++;
					}else{
						uni.showToast({
							title:"请选择品牌",
							icon:"none"
						});
						return false;
					};
				 
				    if(this.nian2 != 0){
				    	tr++;
				    }else{
				    	uni.showToast({
				    		title:"请选择出场年月1",
				    		icon:"none"
				    	});
				    	return false;
				    };
				 
					if(this.yue2 != 0){
						tr++;
					}else{
						uni.showToast({
							title:"请选择出场年月2",
							icon:"none"
						});
						return false;
					};
				 
					if(this.chexing2 != 0){
						tr++;
					}else{
						uni.showToast({
							title:"请选择车型",
							icon:"none"
						});
						return false;
					};
					
					if(this.huji2 != 0){
						tr++;
					}else{
						uni.showToast({
							title:"请选择户籍",
							icon:"none"
						});
						return false;
					};
				 
					if(this.jiage2 != 0){
						tr++;
					}else{
						uni.showToast({
							title:"请选择价格区间",
							icon:"none"
						});
						return false;
					};
					
				    if(reg.test(this.tel)){
						tr++;
					}else{
						uni.showToast({
							title:"请输入正确手机号",
							icon:"none"
						});
						return false;
					};
					
					var dianhua = this.tel;
					var weixin = (this.isChecked1 == false)?0:1;
					var tupian = (this.image666 == '' || this.image666 == 'null')?0:this.image666;
					var uuid = this.id;
					
					uni.request({
						method: "POST",
						url:'http://3697c2a501.imdo.co/cars/carup',
						data:{
							pinpai:this.pinpai1,
							nian:this.nian1,
							yue:this.yue1,
							chexing:this.chexing1,
							huji:this.huji1,
							jiage:this.jiage1,
							dianhua,
							weixin,
							tupian,
							uuid
						},
						dataType:'json',
						header:{
							"content-type" : "application/json"
						},
						 success: (res) => {
								if(res.data == "已上传"){
									uni.showToast({
									title:"您的设备已经上传过信息了！由于服务器资源原因，暂时每个设备仅允许上传一条信息！您可以选择先下架您已发布的信息！您可以到关于中帮助我们！",
									icon:"none"
								})
								}else{
									uni.showToast({
									title:"发布成功！请静候佳音！",
									icon:"none",
								});
								uni.redirectTo({
									url:"../index/index"
								});
								}
								
						    },
						fail() {
							
						}
					})
			},
			queren() {
				var that = this;
				if(this.a == 0){
				uni.request({
					url:"http://3697c2a501.imdo.co/cars/zaime?uuid="+this.id,
					success(data) {
						if(data.data == "已上传"){
							uni.redirectTo({
								url:"../guanli/guanli?id="+that.id
							});
							this.a = 1;
						}
					},
					fail(s) {
						uni.showToast({
							title:"服务器连接超时",
							icon:"none"
						});
						uni.redirectTo({
							url:"../index/index"
						});
						this.a = 1;
					}
				});
				
				}
				if(this.isChecked == false){
					uni.showToast({
						title:"请仔细阅读说明 勾选“我已明了”后点击确定。",
						icon:"none"
					})
				}
				else{
					this.back = false;
				}
			}
			
		}
	}
</script>

<style>
	.biao{
		position: relative;
	}
	.tit1,.tit2,.tit3{
		color:red;
	}
	.pin{
		display:inline-block;
		margin-top: 25rpx;
	}
	.pinpai{
		display: inline-block;
		height:50rpx;
		width: 200rpx;
		margin-left: 15rpx;
		border: 2rpx solid #333333;
	}
	.chu{
		display:inline-block;
		margin-top: 18rpx;
	}
	.nian{
		display:inline-block;
		height:50rpx;
		width: 200rpx;
		margin-left: 15rpx;
		border: 2rpx solid #333333;
	}
	.yue{
		display:inline-block;
		height:50rpx;
		width: 200rpx;
		margin-left: 15rpx;
		border: 2rpx solid #333333;
	}
	.che{
		display:inline-block;
		margin-top: 18rpx;
	}
	.chexing{
		display:inline-block;
		height:50rpx;
		width: 200rpx;
		margin-left: 15rpx;
		border: 2rpx solid #333333;
	}
	.hu{
		display:inline-block;
		margin-top: 18rpx;
	}
	.huji{
		display:inline-block;
		height:50rpx;
		width: 200rpx;
		margin-left: 15rpx;
		border: 2rpx solid #333333;
	}
	.dian{
		display:inline-block;
		margin-top: 18rpx;
	}
	.diandian{
		display:inline-block;
		height:50rpx;
		width: 410rpx;
		margin-left: 15rpx;
		border: 1rpx solid #333333;
		vertical-align: middle;
	}
	.diandian input{
		font-size: 45rpx;
	}
	.wx1{
		display: inline-block;
		transform:scale(0.7);	
		margin-top: 10rpx;
		margin-left: 150rpx;
	}
	.wx2{
		display: inline-block;
		color: #4CD964;
		vertical-align: middle;
	}
	.ida{
		display: inline-block;
		font-size: 30rpx;
		color:red;
	}
	.idb{
		display: inline-block;
		color:#808080
	}
	.bt1{
		display: inline-block;
		margin-top: -35rpx;
		width: 375rpx;
	}
	.bt2{
		display: inline-block;
		margin-top: -35rpx;
		width: 375rpx;

	}
	.tpp{
		position: fixed;
		height: 100%;
		width: 750rpx;
		left:0;
		top: 0;
		background-color: #555555;
		z-index: 100;
	}
	.info{
		width: 550rpx;
		height: 550rpx;
		background-color: #FFFFFF;
		margin: 0 auto;
		margin-top: 400rpx;
		border-radius: 15rpx;
	}
	.tishi{
		height: 60rpx;
		width: 100%;
		text-align: center;
		border-bottom:1rpx solid black;
		font-size: 45rpx;
	}
	.tishi p{
	}
	.ts1{
		display: inline-block;
		transform:scale(0.7);	
		margin-top: 0rpx;
		margin-left: 180rpx;
	}
	.ts2{
		display: inline-block;
		color: red;
		vertical-align: middle;
	}
	.queren{
		margin-top: 35rpx;
		}
	.btt{
		float: right;
		margin-right: 10rpx;
	}
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
</style>
