//=============================================================================
// rpgmv for hbuider
// Version: 1.0
// 
// Copyright (c) 2021 - now lightiun
// Released under the MIT license.
//=============================================================================
//=============================================================================
/*:
 *  @author lightiun ， hbuider
 * @plugindesc 为使用HBuilder打包的安卓mv项目提供更便捷的 退出游戏确认框，自定义震动 调用
 * @help
 * 需要震动手机时使用脚本zhenDong(timec); timec是时间，需要输入数字 单位为ms
 * 在游戏启动页的自动执行事件中执行一次脚本    theBack();  即可启动退出提示
 * 如需关闭退出提示请执行removeBack();
 */
 // 返回框
 function onback(){
	var m;
	try{
	var actionbuttons=[{title:"退出",style:"destructive"}];
	var actionstyle={title:"离开游戏？未保存的内容将丢失",cancel:"取消",buttons:actionbuttons};
	plus.nativeUI.actionSheet(actionstyle, function(e){
		console.log("User pressed: "+e.index );
		if(e.index==1){
			plus.nativeUI.toast("离开游戏");
			plus.runtime.quit();
		}
	});
	}
	catch(err){
		m="非安卓端HBuilder打包无效:\n";
		m+=err.message+".";
		console.log(m);
	}
	
}
// 监听返回事件
function theBack() {
			var m;
	try{
	plus.key.addEventListener("backbutton",onback);
	}
	catch(err){
		m="非安卓端HBuilder打包无效:\n";
		m+=err.message+".";
		console.log(m);
	}
	
}
// 取消监听返回事件
function removeBack(){
try{
	plus.key.removeEventListener("backbutton",onback);
		}
	catch(err){
		m="非安卓端HBuilder打包无效:\n";
		m+=err.message+".";
		console.log(m);
	}
}
//震动
function zhenDong(timec){
	var m;
	try{
		plus.device.vibrate(timec);
	}
	catch(err){
		m="震动";
		m+=err.message+".";
		console.log(m);
	}
}