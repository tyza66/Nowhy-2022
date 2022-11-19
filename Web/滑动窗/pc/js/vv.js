var top = new Vue({
    el:"#ttp",
    data:{
        items:[["首页","番剧","动画","国创"]]
    },

    methods: {
        change(i){
            ni = window.document.getElementById("i");
            if (i == 0){
                ni.setAttribute("src", "html/1.html");
            }
            //下面自己添加即可
        }

    }
})