var pie1 = echarts.init(document.getElementById('pie1'))
option = {
    
    series: [
        {
            name: '访问来源',
            type: 'pie',
            radius: ['100%', '80%'],
            avoidLabelOverlap: false,
            label: {
                show: false,
                position: 'center'
            },
            emphasis: {
                label: {
                    show: true,
                    fontSize: '10',
                    fontWeight: 'bold'
                }
            },
            labelLine: {
                show: false
            },
            data: [
                {value: 9868, name: '98.68'},
                {value: 1000, name: '1.32'},
            ]
        }
    ]
};
pie1.setOption(option);


var pie2 = echarts.init(document.getElementById('pie2'))
option = {
    
    series: [
        {
            name: '访问来源',
            type: 'pie',
            radius: ['100%', '80%'],
            avoidLabelOverlap: false,
            label: {
                show: false,
                position: 'center'
            },
            emphasis: {
                label: {
                    show: true,
                    fontSize: '10',
                    fontWeight: 'bold'
                }
            },
            labelLine: {
                show: false
            },
            data: [
                {value: 9868, name: '97.12'},
                {value: 1320, name: '2.88'},
            ]
        }
    ]
};
pie2.setOption(option);

var pie3 = echarts.init(document.getElementById('pie3'))
option = {
    
    series: [
        {
            name: '访问来源',
            type: 'pie',
            radius: ['100%', '80%'],
            avoidLabelOverlap: false,
            label: {
                show: false,
                position: 'center'
            },
            emphasis: {
                label: {
                    show: true,
                    fontSize: '10',
                    fontWeight: 'bold'
                }
            },
            labelLine: {
                show: false
            },
            data: [
                {value: 9868, name: '97.12'},
                {value: 1320, name: '2.88'},
            ]
        }
    ]
};
pie3.setOption(option);