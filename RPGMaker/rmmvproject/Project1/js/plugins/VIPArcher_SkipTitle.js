//=============================================================================
// VIPArcher_SkipTitle.js
//=============================================================================
 
/*:
 * @plugindesc 彻底跳过默认标题，包括事件里的返回标题和结束游戏时的返回
 * @author VIPArcher
 *
 * @param Test Only
 * @desc 设置为 true 时仅当测试时跳过，设置为 false 时彻底跳过
 * @default true
 * @type boolean
 *
 * @help 这个插件没有需要操作的指令，不需要帮助。
 */
 
void function() {
    var parameters = PluginManager.parameters('VIPArcher_SkipTitle');
    var testOnly = parameters['Test Only'] !== 'false';
    if (!testOnly || Utils.isOptionValid('test')) {
        Scene_Title.prototype.start = function() {
            Stage.prototype.initialize.call(this);
            SceneManager.clearStack();
            DataManager.setupNewGame();
            SceneManager.goto(Scene_Map);
        };
    }
}();