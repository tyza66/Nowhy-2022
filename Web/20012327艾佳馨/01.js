var thisObj;
class Tab{
    constructor(id) {
        thisObj = this ;
        this.tab = document.getElementById(id);
        this.tabul = document.getElementById('tabul');
        this.tabscon = document.getElementById('tabscom');
        this.init();

    }
    init(){
        thisObj.lis = thisObj.tab.querySelectorAll('li');
        thisObj.sections = thisObj.tab.querySelectorAll('section');

        for(var i=0;i<thisObj.lis.length;i++){
            thisObj.lis[i].index =i;
            thisObj.lis[i].onclick =thisObj.toggle;
        }
    }
   //qiehuan
    toggle(){
        thisObj.removeClassName();
        this.className = 'li-active' ;
        thisObj.sections[this.index].className= "con-active";


    }
    removeClassName(){
        for(var i=0;i<thisObj.lis.length;i++){
            thisObj.lis[i].className='';
            thisObj.sections[i].className='';
        }
    }
}
var tab = new Tab('tab');
tab.init();