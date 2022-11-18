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

//1.在指针p所指的节点后面插入一个元素x
int cha1(links *p,int x){
	links *q;
	q = (links *)malloc(sizeof(links));
	q->data = x;
	q->next = p->next;
	p->next = q;
} 

//2.在已知p指针所指向的节点前面插入一个元素x
int cha2(links *L,links *p,int x){
	links *v,*q;
	v = L;
	while(v->next != p) v = v->next;
	if (v == NULL) return 0;
	p = v;
	q = (links *)malloc(sizeof(links));
	q->data = x;
	q->next = p->next;
	p->next = q;
} 

//3.在值为x的元素前插入一个值为y的元素  若x不存在就弄到标尾(^-^)ノ 

int cha3(links *L,int x,int y){
	links *v;	
	v = L->next;
	while(v->data != x && v != NULL) 
	{
		v = v->next;	
	}
	if(v == NULL) cha1(v,y);
	else cha2(L,v,y);
} 

main(){
	links *L = create_2(3);
	cha1(L->next,6); 
	getall(L);
	cha2(L,L->next,6); 
	getall(L);
	cha3(L,3,6); 
	getall(L);
}
