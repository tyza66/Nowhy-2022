/**
 * Created by User on 2021/11/22.
 */
function  setCookie(cookiename,cookievalue,exdays) {
    var d = new Date();
    d.setTime(d.getTime()+(exdays*24*60*60*1000));
    var expires = "expires="+d.toGMTString();
    document.cookie = cookiename + "=" + cookievalue + ";" + expires;
}
function  getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(";");
    for(var i=0;i<ca.length;i++){
        var c = ca[i].trim();
        if(c.indexOf(name)==0){
            return c.substring(name.length,c.length);
        }
    }
    return "";
}
function  checkCookie(cookiekey) {
    var cookievalue = getCookie(cookiekey);
    if(cookievalue!=""){
        alert("hello:"+cookievalue);
    }else{
        var username = window.prompt("起个名字：","");
        if(username!="" && username!=null)
        setCookie("username",username,30);
    }
}