function getCurrentAcceleration(){
		var m;
	try{
	plus.accelerometer.getCurrentAcceleration( function( a ) {
		$gameVariables.setValue(300,parseInt(a.xAxis));
		$gameVariables.setValue(301,parseInt(a.yAxis));
		$gameVariables.setValue(302,parseInt(a.zAxis));
		console.log( "Acceleration\nx:" + a.xAxis + "\ny:" + a.yAxis + "\nz:" + a.zAxis );
	} );
	}
	catch(err){
		m="Rjieie X Pgmo:\n";
		m+=err.message+".";
		console.log(m);
	}
}
function showPicMain(){
$gameScreen.showPicture(1,"101",1,384,216,100,100,255,0);
$gameScreen.showPicture(2,"new",1,350,280,70,70,255,0);
$gameScreen.showPicture(3,"load",1,450,210,70,70,255,0);
$gameScreen.showPicture(4,"set",1,550,280,70,70,255,0);
$gameScreen.showPicture(5,"other",1,650,210,70,70,255,0);
}
function suoDingPicMain(){
$gameVariables.setValue(61,0);
	$gameVariables.setValue(62,0);}
function updatePicMain(){
	getCurrentAcceleration();
	xx=$gameVariables.value(300);
	yy=$gameVariables.value(301);
	zz=$gameVariables.value(302);
	axx=$gameVariables.value(61);
	ayy=$gameVariables.value(62);
	if($gameVariables.value(302)!=90){
	if(yy<0){
$gameVariables.setValue(61,axx+(2*yy));
}
	if(yy>0){
$gameVariables.setValue(61,axx+(2*yy));
}
		if(xx<0){
$gameVariables.setValue(62,ayy+(2*xx));
}
	if(xx>0){
$gameVariables.setValue(62,ayy+(2*xx));
}
	zxx=$gameVariables.value(61);
	zyy=$gameVariables.value(62);
$gameScreen.movePicture(1,1,384+zxx,216+zyy,100,100,255,0,10);
$gameScreen.movePicture(2,1,350+zxx/2,280+zyy/2,70,70,255,0,10);
$gameScreen.movePicture(3,1,450+zxx/2,210+zyy/2,70,70,255,0,10);
$gameScreen.movePicture(4,1,550+zxx/2,280+zyy/2,70,70,255,0,10);
$gameScreen.movePicture(5,1,650+zxx/2,210+zyy/2,70,70,255,0,10);
}}
