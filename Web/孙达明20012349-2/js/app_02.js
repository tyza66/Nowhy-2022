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
        var new_left = current_left + offset ;
        $list.css('left',new_left)
    }
});