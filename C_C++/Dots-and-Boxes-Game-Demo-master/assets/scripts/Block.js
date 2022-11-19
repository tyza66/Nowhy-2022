// Learn cc.Class:
//  - https://docs.cocos.com/creator/manual/en/scripting/class.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

cc.Class({
    extends: cc.Component,

    properties: {
        block_p1_SpriteFrame : {
            default: null,
            type: cc.SpriteFrame
        },
        block_p2_SpriteFrame : {
            default: null,
            type: cc.SpriteFrame
        }
    },

    // LIFE-CYCLE CALLBACKS:

    onLoad () {
        this.occupied = -1;
    },

    start () {

    },

    onOccupy(player){
        if(this.occupied == -1){
            this.occupied = player;
            if(player == 1){
                this.node.getComponent(cc.Sprite).spriteFrame = this.block_p1_SpriteFrame;
            }else{
                this.node.getComponent(cc.Sprite).spriteFrame = this.block_p2_SpriteFrame;
            }
        }
    },

    // update (dt) {},
});
