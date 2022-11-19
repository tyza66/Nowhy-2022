// Learn cc.Class:
//  - https://docs.cocos.com/creator/manual/en/scripting/class.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

cc.Class({
    extends: cc.Component,

    properties: {
        p1_statis : {
            default: null,
            type: cc.Label
        },
        p2_statis : {
            default : null,
            type: cc.Label
        },
        wining_label : {
            default : null,
            type: cc.Label
        }
    },

    // LIFE-CYCLE CALLBACKS:

    // onLoad () {},

    start () {

    },
    onGameOver(p1_score, p2_score){
        this.p1_statis.string = "P1 : " + p1_score;
        this.p2_statis.string = "P2 : " + p2_score;

        if(p1_score > p2_score){
            this.wining_label.string = "P1获胜";
        }else if( p1_score == p2_score){
            this.wining_label.string = "平局";
        }else{
            this.wining_label.string = "P2获胜";
        }
    }
    // update (dt) {},
});
