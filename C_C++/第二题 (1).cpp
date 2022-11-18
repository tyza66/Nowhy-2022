#include<stdio.h>
#include<stdlib.h>
typedef int Ele;

//列表结构体
typedef struct node{
	Ele data;
	struct node *next;
}links;

//初始化链表 传入长度 输入每个节点的数值 
links * create_2(int n)
{
	links *head,*p,*s;
	int i;
	p = head = (links *)malloc(sizeof(links));
	for(i=1;i<=n;i++)
	{
		s = (links *)malloc(sizeof(links));
		scanf("%d",&s->data);
		p->next = s;
		p = s;
	} 
	p->next = NULL;
	return head;
} 

//求链表长度 
int longoflink(links *head)
{
	links *x;
	int n = 0;
	x = head->next;
	while(x != NULL) {n++;x=x->next;}
	return n;
} 

//输出带头节点的单链表i中的所有值 
int getall(links *head)
{
	links *x = head->next;
 	int l = longoflink(head),i;
 	for(i=1;i<=l;i++){
		if(i != l) printf("%d,",x->data);
		else printf("%d\n",x->data);
 		x=x->next;
	 }
}

//1.删除指针p所指向的节点 
int del_one(links *L,links *p){
	links *v;
	v = L;
	while(v->next != p) v = v->next;
	if (v == NULL) return 0;
	v->next = p->next;
	free(p);
} 


//2.删除表中值为x的数据元素 不存在返回0 

int del_two(links *L,int x){
	links *v;	
	v = L->next;
	while(v->data != x && v != NULL) 
	{
		v = v->next;	
	}
	if(v == NULL) return 0;
	else 
	{
		del_one(L,v);
		return 1;
	}
} 

main(){
	links *L = create_2(3);
	del_one(L,L->next); 
	getall(L);
	del_two(L,2); 
	getall(L);
}
