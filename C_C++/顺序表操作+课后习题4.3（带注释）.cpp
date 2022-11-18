#include<stdio.h>
#include<stdlib.h>
//创建表的机构体变量类型 
typedef struct
{
	int *data;
	int len;
	int size;
} biao;

//初始化表项 
biao create_1(biao *L)
{
	L->data = (int *)malloc(sizeof(int)*30);
	L->len = 0;
	L->size = 30;
};

//在第i位增加一个数据 增  成功返回1 失败返回0 
int insert(biao *L,int i,int x)
{
	int temp;
	if(i<1||i>L->len) return 0;
	if(L->len == L->size)
		{
			L->data=(int *)realloc(L->data,(L->size+1)*sizeof(int));
			L->size++;
		}
	for(temp=L->len-1;temp>=i-1;temp--)
		{
			L->data[temp+1] = L->data[temp];
		}
	L->data[i-1] = x;
	L->len++;
	return 1;
}

//手动往表里输入i个值 增
int gget(biao *L,int i)
{
	int temp,temp1;
	if(L->len+i > L->size)
		{
			L->data=(int *)realloc(L->data,(L->size+(L->len+i-L->size))*sizeof(int));
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
//把第i位的数据改成指定值 改 成功返回1 失败返回0 
int change1(biao *L,int i,int x)
{
	if(i<1||i>L->len) return 0;
	L->data[i-1] = x;
	return 1;
}

//获取长度 查 
int getlen(biao *L)
{
	return (L->len);
} 

//获取大小 查 
int getsize(biao *L)
{
	return (L->size);
} 

//获得序号为i的元素 查 
int getdatabyid(biao *L,int i) 
{
	return (L->data[i-1]);
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
//元素定位 获得第一个和指定值相等的元素的位置 查 没查到返回-1 
int where(biao *L,int a)
{
	int temp;
	for(temp=0;temp<L->len;temp++)
		{
			if(L->data[temp] == a)	
			{
				printf("%d");
				return (temp+1);
			}
			
		}
	return -1;
}
 
//删除表中大于x小于y的元素  删 成功返回1 失败返回0 
int delxy(biao *L,int x,int y)
{
	int temp;
	for(temp=0;temp<L->len;temp++)
		{
			if(L->data[temp]>=x&&L->data[temp]<=y)	del(L,temp+1);
		}
}
//主函数 
main()
{
	 biao L;
	 create_1(&L);
	 gget(&L,5);
	 delxy(&L,3,5);
	 getall(&L);
};

