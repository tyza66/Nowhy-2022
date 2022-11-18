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

//取第i个链表中的节点 
links * geti(links *head,int i)
{
	links *x;
	int n=0;
	x = head->next;
	while(x != NULL){
		if(n+1==i) return x; 
		n++;
		x=x->next;
	}
} 

//按值由大到小重新排列链表
int rescroll(links *head)
{
	int i,j;
	int a = longoflink(head);
	links *x = head,*y,*z,*h,*w,*f,*g;
	for(i=1;i<=a;i++)
	{
		for(j=i+1;j<=a;j++)
		{
			if(geti(x,j)->data>geti(x,i)->data)
			{
				if(i==1)
				{
					y = x->next;
					z = geti(x,i)->next;
					h = geti(x,j-1)->next;
					w = geti(x,j)->next;
					x->next = h;
					geti(x,i)->next = z;
					geti(x,j-1)->next = y;
					geti(x,j)->next = w;
				}
				else{ 
					y = geti(x,i-1)->next;
					z = geti(x,i)->next;
					h = geti(x,j-1)->next;
					w = geti(x,j)->next;
					geti(x,i-1)->next = h;
					geti(x,i)->next = z;
					geti(x,j-1)->next = y;
					geti(x,j)->next = w;
				}
			}
		}
	}
} 

//俩非递减链表合一成非递增  不开新空间
void Merge_List(links *La,links *Lb) {
	links *L,*p,*q;
	rescroll(La);
	rescroll(Lb);
	L = La;
	p = La->next;
	q = Lb->next;
	while(p != NULL && q != NULL) {
		if(p->data > q->data){
			L->next = p;
			p = p->next;	
		}
		else{
			L->next = q;
			q = q->next;
		}
			L = L->next;
	}
	if(p == NULL) L->next = q;
	if(q == NULL) L->next = p;
}

main(){
	links *a1 = create_2(4);
	links *a2 = create_2(5);
	Merge_List(a1,a2);
	getall(a1);
} 
