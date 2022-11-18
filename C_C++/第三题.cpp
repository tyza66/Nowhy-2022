#include<stdio.h>
#include<stdlib.h>
typedef int Ele;
//列表结构体
typedef struct node{
	Ele data;
	struct node *prior,*next;
}links;

//初始化双向循环链表 传入长度 输入每个节点的数值 
links * create_3(int n)
{
	links *head,*p,*s;
	int i;
	p = head = (links *)malloc(sizeof(links));
	for(i=1;i<=n;i++)
	{
		s = (links *)malloc(sizeof(links));
		scanf("%d",&s->data);
		p->next = s;
		s->prior = p;
		p = s;
	} 
	p->next = head->next;
	head->next->prior = p;
	return head;
} 

//求链表长度 
int longoflink(links *head)
{
	links *x;
	int n = 0;
	x = head->next;
	while(x->next != head->next) {n++;x=x->next;}
	return n+1;
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

//大于零的放在小于0的前面
int daxiao(links *head) {
	links *v,*p,*q;
	Ele temp;
	p = head->next;
	q = head->next;
	while(q->next != p) q = q->next;
	while(p != q){
		if(p->data < 0 && q->data > 0){
				temp = p->data;
				p->data = q->data;
				q->data = temp;	
		}
		else if(p->data > 0 ){
			p = p->next;
		}
		else{
			q = q->prior;
		}
	} 
}
 
main(){
	links *L = create_3(6);
	daxiao(L);
	getall(L);
} 

//答：双向链表可以倒车，所以可以双向替换 