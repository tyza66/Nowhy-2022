var li1 = document.getElementById("jp_list")
function jp_form_auto() {
    var n = 1;
    var h ;
    for(var i = 1 ; i <= li1.children[0].children.length ; i++){
        if(i % 5 === 0) n++;
    }
    h = 110 * n;
    li1.style.height = h + 'px';
}

jp_form_auto();


var li2 = document.getElementById("tp_list")
function tp_form_auto() {
    var n = 1;
    var h ;
    for(var i = 1 ; i <= li2.children[0].children.length ; i++){
        if(i % 5 === 0) n++;
    }
    h = 110 * n;
    li2.style.height = h + 'px';
}

tp_form_auto();


var li3 = document.getElementById("yx_list")
function yx_form_auto() {
    var n = 1;
    var h ;
    for(var i = 1 ; i <= li3.children[0].children.length ; i++){
        if(i % 5 === 0) n++;
    }
    h = 110 * n;
    li3.style.height = h + 'px';
}

yx_form_auto();


var li4 = document.getElementById("dm_list")
function dm_form_auto() {
    var n = 1;
    var h ;
    for(var i = 1 ; i <= li4.children[0].children.length ; i++){
        if(i % 5 === 0) n++;
    }
    h = 110 * n;
    li4.style.height = h + 'px';
}

dm_form_auto();