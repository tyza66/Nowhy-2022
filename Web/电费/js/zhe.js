var zhu1 = echarts.init(document.getElementById('tiao'))
option = {
    tooltip: {
        trigger: 'axis',
        axisPointer: {
            type: 'cross',
            crossStyle: {
                color: '#999'
            }
        }
    },
    toolbox: {
        feature: {
            dataView: {show: true, readOnly: false},
            magicType: {show: true, type: ['line', 'bar']},
            restore: {show: true},
            saveAsImage: {show: true}
        }
    },
    legend: {
        data: ['应收电量', '实收电量', '电费回收率']
    },
    xAxis: [
        {
            type: 'category',
            data: ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12'],
            axisPointer: {
                type: 'shadow'
            }
        }
    ],
    yAxis: [
        {
            type: 'value',
            name: '单位:万元',
            min: 0,
            max: 60,
            interval: 15,
            axisLabel: {
                formatter: '{value} '
            }
        },
        {
            type: 'value',
            name: '百分比',
            min: 0,
            max: 100,
            interval: 25,
            axisLabel: {
                formatter: '{value} '
            }
        }
    ],
    series: [
        {
            name: '应收电量',
            type: 'bar',
            data: [2.0, 4.9, 7.0, 23.2, 25.6, 56.7, 55.6, 52.2, 32.6, 20.0, 6.4, 3.3]
        },
        {
            name: '实收电量',
            type: 'bar',
            data: [2.6, 5.9, 9.0, 26.4, 28.7, 60.0, 55.6, 52.2, 48.7, 18.8, 6.0, 2.3]
        },
        {
            name: '电费回收率',
            type: 'line',
            yAxisIndex: 1,
            data: [2.0, 2.2, 3.3, 4.5, 6.3, 10.2, 20.3, 23.4, 23.0, 16.5, 12.0, 6.2]
        }
    ]
};
zhu1.setOption(option);