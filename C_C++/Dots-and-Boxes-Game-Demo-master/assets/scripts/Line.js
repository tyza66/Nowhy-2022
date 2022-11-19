// Learn cc.Class:
//  - https://docs.cocos.com/creator/manual/en/scripting/class.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

cc.Class({
    extends: cc.Component,

    properties: {
        // foo: {
        //     // ATTRIBUTES:
        //     default: null,        // The default value will be used only when the component attaching
        //                           // to a node for the first time
        //     type: cc.SpriteFrame, // optional, default is typeof default
        //     serializable: true,   // optional, default is true
        // },
        // bar: {
        //     get () {
        //         return this._bar;
        //     },
        //     set (value) {
        //         this._bar = value;
        //     }
        // },
        origin_spriteFrame : {
            default : null,
            type: cc.SpriteFrame
        },
        origin_opacity : 255,
        p1_spriteFrame : {
            default : null,
            type: cc.SpriteFrame
        },
        p2_spriteFrame : {
            default : null,
            type: cc.SpriteFrame
        },
        
    },

    // LIFE-CYCLE CALLBACKS:

    onLoad () {
        // 刚开始是黑色，透明度
        this.node.opacity = this.origin_opacity;
        this.node.getComponent(cc.Sprite).spriteFrame = this.origin_spriteFrame;
        this.occupied = -1;
    },

    start () {
        this.node.on(cc.Node.EventType.TOUCH_START,this.onTouch,this);
    },
    onTouch(event){
        event.currentTarget.getComponent("Line").onOccupy(this.game.currentPlayer);
    },

    onOccupy(player){
        if(this.occupied == -1 ){
            this.node.off(cc.Node.EventType.TOUCH_START,this.onTouch,this);
            if(player == 1){
                this.occupied = 1;
                this.node.opacity = 255;
                this.node.getComponent(cc.Sprite).spriteFrame = this.p1_spriteFrame;
            }else if(player == 2){
                this.occupied =2;
                this.node.opacity = 255;
                this.node.getComponent(cc.Sprite).spriteFrame = this.p2_spriteFrame;
            }
            this.game.checkComplete();
        }
    }

});
