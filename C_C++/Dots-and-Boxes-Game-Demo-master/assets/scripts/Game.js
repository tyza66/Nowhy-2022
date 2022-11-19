// Learn cc.Class:
//  - https://docs.cocos.com/creator/manual/en/scripting/class.html
// Learn Attribute:
//  - https://docs.cocos.com/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - https://docs.cocos.com/creator/manual/en/scripting/life-cycle-callbacks.html

cc.Class({
    extends: cc.Component,

    properties: {
        label_p1 : {
            default: null,
            type: cc.Label
        },
        label_p2 : {
            default: null,
            type: cc.Label
        },
        board : {
            default: null,
            type: cc.Sprite
        },
        endWindow : {
            default : null,
            type: cc.Prefab
        }
    },

    // LIFE-CYCLE CALLBACKS:

    onLoad () {
        this.currentPlayer = 1;
    },

    start () {
        this.label_p1.getComponent("Label").onActivate();
    },
    // update (dt) {},

    switchPlayer(){
        if(this.currentPlayer == 1){
            this.label_p1.getComponent("Label").onDeactivate();
            this.label_p2.getComponent("Label").onActivate();
            this.currentPlayer = 2;
        }else if(this.currentPlayer == 2){
            this.label_p1.getComponent("Label").onActivate();
            this.label_p2.getComponent("Label").onDeactivate();
            this.currentPlayer = 1;
        }
    },

    checkComplete(){
        cc.log(this.board.getComponent('Board').blocks);
        cc.log(this.board.getComponent('Board').lines);
        let blocks = this.board.getComponent('Board').blocks;
        let lines = this.board.getComponent('Board').lines;
        let width = this.board.getComponent('Board').width;
        let height = this.board.getComponent('Board').height;
        let changePlayer = true;
        let p1_completed_blocks = 0;
        let p2_completed_blocks = 0;
        for(let i = 0 ; i< blocks.length; ++i)
        {
            let block_id = i;
            let col = block_id % width;
            let row = Math.floor(block_id / width);
            if(blocks[block_id].getComponent('Block').occupied != -1){
                // 被占领了
                if(blocks[block_id].getComponent('Block').occupied == 1){
                    p1_completed_blocks +=1;
                }else if(blocks[block_id].getComponent('Block').occupied == 2){
                    p2_completed_blocks +=1;
                }
            }else{
                let newOccupy = true;
                let lines_id = [row * 13 + col, row*13 + col + 13, row* 13 + col + 6, row*13 + col + 7];
                for(let j =0; j < lines_id.length; ++j){
                    if(lines[lines_id[j]].getComponent('Line').occupied != -1){
                        // 被占领了
                    }else{
                        newOccupy = false;
                    }
                }
                if(newOccupy){
                    // 填满一格
                    cc.log("block: " ,block_id , " completed");
                    blocks[block_id].getComponent('Block').onOccupy(this.currentPlayer);

                    if(this.currentPlayer == 1){
                        p1_completed_blocks += 1;
                    }else if( this.currentPlayer == 2){
                        p2_completed_blocks += 1;
                    }
                    changePlayer = false;
                }
            }
        }

        // check if game end
        if(p1_completed_blocks + p2_completed_blocks == width * height){
            // game end
            this.onGameOver(p1_completed_blocks,p2_completed_blocks);
        }
        if(changePlayer){
            this.switchPlayer();
        }
    },
    onGameOver (p1_completed_blocks, p2_completed_blocks){
        this.label_p1.destroy();
        this.label_p2.destroy();

        var endWindow = cc.instantiate(this.endWindow);
        endWindow.getComponent('Statis').onGameOver(p1_completed_blocks, p2_completed_blocks);
        this.node.addChild(endWindow);
    }
});
