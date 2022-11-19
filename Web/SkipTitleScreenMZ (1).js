//=============================================================================
// SkipTitleScreenMZ.js v1.0
//=============================================================================

/*:
 * @target MZ
 * @plugindesc 跳过标题画面.
 * @author  DonF204 
 */

/*:de
 * @target MZ
 * @plugindesc Ein Plug-In um den Title Screen zu Ã¼berspringen.
 * @author [DonGang] DonF204
 */

(function() {

    Scene_Boot.prototype.startNormalGame = function() {
        this.checkPlayerLocation();
        DataManager.setupNewGame();
        $autoSave = $dataSystem.optAutosave;
        SceneManager.goto(Scene_Map);
    };
    
    Scene_Gameover.prototype.gotoTitle = function() {
        $dataSystem.optAutosave = false;
        DataManager.setupNewGame();
        SceneManager.goto(Scene_Map);
    };

    Scene_GameEnd.prototype.commandToTitle = function() {
        $dataSystem.optAutosave = false;
        DataManager.setupNewGame();
        SceneManager.goto(Scene_Map);
    };

    Game_Interpreter.prototype.command354 = function() {
        $dataSystem.optAutosave = false;
        DataManager.setupNewGame();
        SceneManager.goto(Scene_Map);
        return true;
    };

    Scene_Map.prototype.start = function() {
        Scene_Message.prototype.start.call(this);
        SceneManager.clearStack();
        if (this._transfer) {
            this.fadeInForTransfer();
            this.onTransferEnd();
        } else if (this.needsFadeIn()) {
            this.startFadeIn(this.fadeSpeed(), false);
        }
        this.menuCalling = false;
        $dataSystem.optAutosave = $autoSave;
    };

})();
