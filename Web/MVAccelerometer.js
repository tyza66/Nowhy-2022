//=============================================================================
// rpgmv for hbuider
// Version: 1.0
// Released under the MIT license.
//=============================================================================
//=============================================================================
/*:
 *  @author lightiun ， hbuider
 * @plugindesc 令使用HBuilder打包的安卓mv项目获取手机加速度传感器信息
 * @help
 * getAcc(ida,idb,idc)
 * ida idb idc 分别为您要写入的变量编号
 * ida写入加速度传感器x值 idb写入加速度传感器y值 idc写入加速度传感器z值
 */
function getAcc(ida,idb,idc){
		var m;
	try{
	plus.accelerometer.getCurrentAcceleration( function( a ) {
		$gameVariables.setValue(ida,parseInt(a.xAxis));
		$gameVariables.setValue(idb,parseInt(a.yAxis));
		$gameVariables.setValue(idc,parseInt(a.zAxis));
		console.log( "Acceleration\nx:" + a.xAxis + "\ny:" + a.yAxis + "\nz:" + a.zAxis );
	} );
	}
	catch(err){
		m="打包安卓有效";
		m+=err.message+".";
		console.log(m);
	}
}