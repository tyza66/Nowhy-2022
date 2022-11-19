// Learn cc.Class:
//  - https://docs.cocos.com/creator/manual/en/scripting/class.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

cc.Class({
    extends: cc.Component,

    properties: {
        line : {
            default : null,
            type: cc.Prefab
        },
        dot : {
            default : null,
            type: cc.Prefab
        },
        block : {
            default : null,
            type: cc.Prefab
        },
        width : 6,
        height : 4,
        line_length : 100,
    },

    // LIFE-CYCLE CALLBACKS:

    onLoad () {
        // generate dot width + 1 * height + 1
        this.node.width = this.width * this.line_length;
        this.node.height = this.height * this.line_length;
        for(let i =0 ; i < this.width + 1; ++i){
            for(let j=0; j < this.height + 1; ++j){
                var dot = cc.instantiate(this.dot);
                this.node.addChild(dot);
                dot.setPosition(i * this.line_length,j * this.line_length);
            }
        }

        // generate block width * height
        let block_indice = 0;
        this.blocks = [];
        for(let i =0; i< this.height; ++i){
            for(let j=0; j<this.width; ++j){
                var block = cc.instantiate(this.block);
                this.node.addChild(block,1,'block'+block_indice);
                this.blocks.push(block);
                block.setPosition(j * this.line_length + this.line_length / 2 , i * this.line_length + this.line_length / 2);
                block.width = this.line_length;
                block.height = this.line_length;
                block_indice += 1 ;
            }
        }

        // generate line
        this.lines = [];
        let line_indice = 0;
        for(let i = 0;  i < this.height ; ++i){
            for(let j =0; j < this.width * 2 + 1; ++j){
                // 前width 个位横线 , 后width + 1个为竖线
                var line = cc.instantiate(this.line);
                this.node.addChild(line,1,"line"+line_indice);
                this.lines.push(line);
                line.width = this.line_length;
                line.getComponent("Line").game = this.node.getParent().getComponent("Game"); 
                if(j < this.width){
                    line.setPosition(j * this.line_length + this.line_length/2, i * this.line_length);
                }else{
                    let vj = j - this.width;
                    line.setPosition(vj * this.line_length, i* this.line_length + this.line_length / 2);
                    line.angle = 90;
                }
                line_indice += 1;
            }
        }
        for(let j =0; j < this.width; ++j){
            line_indice +=1;
            var line = cc.instantiate(this.line);
            this.node.addChild(line,1,"line"+line_indice);
            this.lines.push(line);
            line.width = this.line_length;
            line.getComponent("Line").game = this.node.getParent().getComponent("Game"); 
            line.setPosition(j * this.line_length + this.line_length/2, this.height * this.line_length);
        }
    },

    start () {

    },


    // update (dt) {},
});
