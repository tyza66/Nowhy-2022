var swiper = new Vue({
    el:"#sw1",
    data:{
        pics:["https://i2.hdslb.com/bfs/face/9517a7cb97a237d3548de571ba61e1cc62731c0c.jpg@140w_140h_1c.webp","https://i2.hdslb.com/bfs/face/b35f0f68e751172f31b3bb77b0c6fe007718fe37.jpg@96w_96h_1c.webp"]
    }
})

var jp = new Vue({
    el:"#jp_list",
    data:{
        items:[]
    },
    mounted:function(){
        this.go();

    },
    methods: {
        go:function(){
       
    }
}})

