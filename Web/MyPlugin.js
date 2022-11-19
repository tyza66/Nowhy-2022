//=============================================================================
// MyPlugin.js
//=============================================================================

/*:
 * @plugindesc This is plugin description.
 * @author This is author.
 * @help This is help.
 *
 * @param ------Group1------
 * @default 
 *
 * @param ------Group2------
 * @default 
 *
 * @param StringParam
 * @parent ------Group1------
 * @desc This is string type param.
 * @type string
 * @default abc
 *
 * @param NumberParam
 * @parent ------Group1------
 * @desc This is number type param.
 * @type number
 * @min 1
 * @max 100
 * @default 0
 *
 * @param BooleanParam
 * @parent ------Group1------
 * @desc This is boolean type param.
 * @type boolean
 * @on Open
 * @off Close
 * @default true
 *
 * @param VariableParam
 * @parent ------Group1------
 * @desc This is variable type param.
 * @type variable
 * @default 1
 * 
 * @param SelectParam
 * @parent ------Group1------
 * @type select
 * @option Selection1
 * @value 0
 * @option Selection2
 * @value 1
 * @desc This is select type param.
 * @default 0
 *
 * @param FileParam
 * @desc This is file type param.
 * @type file
 * @dir audio/se/
 * @default Absorb1
 * @require 1
 * 
 * @param ActorParam
 * @parent ------Group2------
 * @desc This is actor type param.
 * @type actor
 * @default 1
 *
 * @param ClassParam
 * @parent ------Group2------
 * @desc This is class type param.
 * @type class
 * @default 1
 *
 * @param ItemParam
 * @parent ------Group2------
 * @desc This is item type param.
 * @type item
 * @default 1
 *
 * @param SkillParam
 * @parent ------Group2------
 * @desc This is skill type param.
 * @type skill
 * @default 1
 *
 * @param WeaponParam
 * @parent ------Group2------
 * @desc This is weapon type param.
 * @type weapon
 * @default 1
 *
 * @param ArmorParam
 * @parent ------Group2------
 * @desc This is armor type param.
 * @type armor
 * @default 1
 *
 * @param EnemyParam
 * @parent ------Group2------
 * @desc This is enemy type param.
 * @type enemy
 * @default 1
 *
 * @param TroopParam
 * @parent ------Group2------
 * @desc This is troop type param.
 * @type troop
 * @default 1
 *
 * @param StateParam
 * @parent ------Group2------
 * @desc This is state type param.
 * @type state
 * @default 1
 * 
 * @param AnimationParam
 * @parent ------Group2------
 * @descThis is animation type param.
 * @type animation
 * @default 1
 * 
 * @param TilesetParam
 * @parent ------Group2------
 * @desc This is tileset type param.
 * @type tileset
 * @default 1
 *
 * @param CommonEventParam
 * @desc This is common_event type param.
 * @type common_event
 * @default 1
 *
 */

/*:zh
 * @plugindesc 这是插件描述。
 * @author 这是作者。
 * @help 这是帮助。
 *
 * @param ------分组1------
 * @default  
 *
 * @param ------分组2------
 * @default 
 *
 * @param 文本参数
 * @parent ------分组1------
 * @desc 这是个文本类型的参数。
 * @type string
 * @default abc
 *
 * @param 数字参数
 * @parent ------分组1------
 * @desc 这是个数字类型的参数。
 * @type number
 * @min 1
 * @max 100
 * @default 1
 *
 * @param 布尔值参数
 * @parent ------分组1------
 * @desc 这是个布尔值类型的参数。
 * @type boolean
 * @on 开启
 * @off 关闭
 * @default true
 *
 * @param 变量参数
 * @parent ------分组1------
 * @desc 这是个变量类型的参数。
 * @type variable
 * @default 1
 *
 * @param 选项参数
 * @parent ------分组1------
 * @type select
 * @option 选项1
 * @value 0
 * @option 选项2
 * @value 1
 * @desc 这是个选项类型的参数。
 * @default 0
 *
 * @param 文件参数
 * @desc 这是个文件类型的参数。
 * @type file
 * @dir audio/se/
 * @default Absorb1
 *
 * @param 角色参数
 * @parent ------分组2------
 * @desc 这是个角色类型的参数。
 * @type actor
 * @default 1
 *
 * @param 职业参数
 * @parent ------分组2------
 * @desc 这是个职业类型的参数。
 * @type class
 * @default 1
 *
 * @param 物品参数
 * @parent ------分组2------
 * @desc 这是个物品类型的参数。
 * @type item
 * @default 1
 *
 * @param 技能参数
 * @parent ------分组2------
 * @desc 这是个技能类型的参数。
 * @type skill
 * @default 1
 *
 * @param 武器参数
 * @parent ------分组2------
 * @desc 这是个武器类型的参数。
 * @type weapon
 * @default 1
 *
 * @param 护甲参数
 * @parent ------分组2------
 * @desc 这是个护甲类型的参数。
 * @type armor
 * @default 1
 *
 * @param 敌人参数
 * @parent ------分组2------
 * @desc 这是个敌人类型的参数。
 * @type enemy
 * @default 1
 *
 * @param 敌群参数
 * @parent ------分组2------
 * @desc 这是个敌群类型的参数。
 * @type troop
 * @default 1
 *
 * @param 状态参数
 * @parent ------分组2------
 * @desc 这是个状态类型的参数。
 * @type state
 * @default 1
 * 
 * @param 动画参数
 * @parent ------分组2------
 * @desc 这是个动画类型的参数。
 * @type animation
 * @default 1
 * 
 * @param 图块参数
 * @parent ------分组2------
 * @desc 这是个图块类型的参数。
 * @type tileset
 * @default 1
 *
 * @param 公共事件参数
 * @parent ------分组2------
 * @desc 这是个公共事件类型的参数。
 * @type common_event
 * @default 1
 *
 */
(function() {

    var parameters = PluginManager.parameters('MyPlugin');

    var param1 = parameters['StringParam'] || parameters['文本参数'];
    var param2 = Number(parameters['NumberParam'] || parameters['数字参数']);
    var param3 = JSON.parse(parameters['BooleanParam'] || parameters['布尔值参数']);
    var param4 = Number(parameters['VariableParam'] || parameters['变量参数']);
    var param5 = parameters['FileParam'] || parameters['文件参数'];
    var param6 = parameters['SelectParam'] || parameters['选项参数'];
    var param7 = Number(parameters['CommonEventParam'] || parameters['公共事件参数']);

    var _Game_Interpreter_pluginCommand = Game_Interpreter.prototype.pluginCommand;
    Game_Interpreter.prototype.pluginCommand = function(command, args) {
        _Game_Interpreter_pluginCommand.call(this, command, args);
        if (command === 'Console_Log') {
            console.log(args);
        } else if (command == 'Alert') {
            alert(args);
        }
    };

    Game_Action.prototype.applyCritical = function(damage) {
        return damage * 4;
    };

    var _Game_Action_applyCritical = Game_Action.prototype.applyCritical;
    Game_Action.prototype.applyCritical = function(damage) {
        var value = _Game_Action_applyCritical.call(this, damage);
        return value + 100;
    };

})();