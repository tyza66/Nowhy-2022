/**
 * Created by User on 2021/12/6.
 */
$(function(){
    var $container = $('#container');
    var $list=$('#list');
    var $prev = $('#prev');
    var $next = $('#next');
    var PAGEWIDTH = 600;

    var NEXT = true;
    var PREV = false;

    var TIME = 400;
    var TIME_UNIT = 20;

    //为click事件定义事件处理function
    $next.click( function(){
        nextPage( NEXT );
    } );
    $prev.click( function(){
        nextPage( PREV );
    } );
    function nextPage(next_or_prev) {
        var current_left = $list.position().left;
        var offset = next_or_prev ? -PAGEWIDTH : PAGEWIDTH;
        var offset_unit = offset / (TIME/TIME_UNIT);
        var target_left = current_left +offset;
        var a = 1;
        var intervalId =setInterval(
            function(){
                if(current_left == target_left){
                    clearInterval(intervalId);
                }
                if(a<=20){
                    $list.css('left',current_left + offset_unit);
                    current_left = current_left + offset_unit;
                    a++;
                }

            },
            TIME_UNIT
        );
        $list.css('left',new_left);

    }
});
