#include<stdio.h>
#include<stdlib.h>
typedef int Ele;
//创建表的机构体变量类型 
typedef struct
{
	Ele *data;
	int len;
	int size;
} biao;

//初始化表项 
biao create_1(biao *L)
{
	L->data = (Ele *)malloc(sizeof(Ele)*30);
	L->len = 0;
	L->size = 30;
};

//手动往表里输入i个值 增
int gget(biao *L,int i)
{
	int temp,temp1;
	if(L->len+i > L->size)
		{
			L->data=(Ele *)realloc(L->data,(L->size+(L->len+i-L->size))*sizeof(Ele));
			L->size++;
		}
	for(temp=0;temp<i;temp++)
		{
			scanf("%d",&temp1);
			L->data[temp] = temp1;
			L->len++;
		}
}

//删除第i位的数据 删 成功返回1 失败返回0 
int del(biao *L,int i)
{
	int temp;
	if(i<1||i>L->len) return 0;
	for(temp=i-1;temp<=L->len-1;temp++)
		{
				L->data[temp] = L->data[temp+1];
		} 
	L->len--;
	return 1;
}

//显示表中所有的元素的值 查 
int getall(biao *L)
{
	int temp;
	for(temp=0;temp<L->len;temp++)
		{
			if(temp!=L->len-1)	printf("%d,",L->data[temp]);
			else  	printf("%d\n",L->data[temp]);
		}
}

 
//删除表中大于x小于y的元素  删 成功返回1 失败返回0 
int delxy(biao *L,int x,int y)
{
	int temp;
	for(temp=0;temp<L->len;temp++)
		{
			if(L->data[temp]>=x&&L->data[temp]<=y)
			{
				del(L,temp+1);
				temp--;
			}	
			
		}
}
//主函数 
main()
{
	 biao L;
	 create_1(&L);
	 gget(&L,5);
	 delxy(&L,1,3);
	 getall(&L);
};

