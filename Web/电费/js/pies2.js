var pie4 = echarts.init(document.getElementById('pie4'))
option = {
    tooltip: {
        trigger: 'item'
    },
    legend: {
        top: '5%',
        left: 'left',
        orient: 'vertical'
    },
    series: [
        {
            name: '访问来源',
            type: 'pie',
            radius: ['80%', '50%'],
            avoidLabelOverlap: false,
            label: {
                show: false,
                position: 'center'
            },
            emphasis: {
                label: {
                    show: true,
                    fontSize: '40',
                    fontWeight: 'bold'
                }
            },
            labelLine: {
                show: false
            },
            data: [
                {value: 1048, name: '大工业'},
                {value: 735, name: '一般工商业'},
                {value: 580, name: '城镇居民用电'},
                {value: 484, name: '农村居民用电'},
                {value: 300, name: '农业生产'},
                {value: 300, name: '小水电下网'},
                {value: 300, name: '商业用电'}
            ]
            
        }
    ]
};

pie4.setOption(option);