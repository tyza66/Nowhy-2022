
/* 线性表的链式存储 */
#include "stdio.h"
/* 结点类型 */
#define ElemType int
typedef struct node
{ ElemType data;
  struct node *next;
} slink;

/*初始化操作*/
slink *initlist()
{
  slink *L;
  L=(slink *)malloc(sizeof(slink)); /* 指向头结点 */
  L->next=NULL;
  return L;
}


/*求表长操作*/
int getlen(slink *L)
{
 int i=0;
 slink *p=L->next;
 while(p!=NULL)
   {i++;p=p->next;}
 return i;
}

/*取数据元素操作*/
slink *getelem(slink *L,int i)
{
 int j=1;
 slink *p=L->next;
 if(i<1||i>getlen(L))
   return NULL;         /* i不合法，返回NULL */
 while(j<i)             /*从第1个结点开始查找第i个结点*/
   {p=p->next;j++;}
   return p;            /* 返回第i个结点的指针 */
}

/*定位操作*/
locate(slink *L,ElemType x)
{
  int i=1;
  slink *p=L->next;
  while(p!=NULL&&p->data!=x)  /*从第一个结点开始查找data域值为x的结点*/
    {p=p->next;i++;}
  if(p==NULL) return 0;    /*没找到后0，否则返回其位序*/
  else return i;
}

 /* 写出在带头结点的单向链表l中删除第i个结点的算法 */

delete(slink *L,int i)
{
 slink *p,*q;
 int j=0;
 p=L;
 if(i>getlen(L)||i<1)
   return 0;
 else
  {
   while(j<i-1)
     {p=p->next;j++;}        /*从第一个结点开始查找第i-1个结点，由p指向它*/
   q=p->next;
   p->next=q->next;
   free(q);
   return 1;
 }
}

 /* 写出在带头结点的单向链表l中第i个结点前插入一个结点的算法 */

insert(slink *L,ElemType x,int i)
{
 slink *p,*q;
 int j=0;
 p=L;
 q=(slink *)malloc(sizeof(slink));    /*创建data域为x的结点*/
 q->data=x;
 q->next=NULL;
 if(i<1||i>getlen(L)+1)
   return 0;
 else
 {
   while(j<i-1)
     {p=p->next;j++;}         /*从第一个结点开始查找第i-1个结点，由p指向它*/
   q->next=p->next;
   p->next=q;
   return 1;
 }
}

/* 写出输出带头结点的单向链表l的算法 */

void print(slink *L)
{
 slink *p;
 p=L->next;
 while(p!=NULL)
   { printf("%4d",p->data);
     p=p->next;
   }
}

/* 写出将两个带头结点的单向链表a和b连接起来的算法 */

void link(slink *a,slink *b)
{ slink *p;
  p=a;
  while(p->next!=NULL) p=p->next;
  p->next=b->next;
  free(b);
}

/* 写出将两个带头结点的单向链表归并的算法 */


void merge(slink *la,slink *lb)
{
 slink *pa,*pb,*pc;
 pa=la->next;
 pb=lb->next;
 pc=la;
 while(pa!=NULL&&pb!=NULL)
  {
   if((pa->data)<=(pb->data))
    {pc->next=pa;pc=pc->next;pa=pa->next;}
   else
    {pc->next=pb;pc=pc->next;pb=pb->next;}
  }
 if(pa!=NULL)
   pc->next=pa;
 else
      pc->next=pb;
 free(lb);
}

/* 写出将两个带头结点的单向链表合并的算法 */
void bring(slink *la,slink *lb)
{
 slink *l;
 int i;
 l=lb->next;
 while(l!=NULL)
   { i=locate(la,l->data);
     if(i!=0)
       delete(la,i);
     l=l->next;
  }
  l=la;
  while(l->next!=NULL) l=l->next;
  l->next=lb->next;
}

/* 写出将线性表 l 逆置的算法  方法一 */

/* 此算法的时间复杂度为 T(n)=O(n*n)*/

void turn1(slink *L)
{
 slink *p,*q;
 slink *new,*newl;
 new=NULL;
 newl=NULL;
 while(L->next!=NULL)
 { p=L;
   while(p->next!=NULL) {q=p;p=p->next;}
   if(new==NULL) {new=p;newl=p;q->next=NULL;}
   else {new->next=p;new=new->next;q->next=NULL;}
 }
 new->next=NULL; /*尾指针赋空*/
 L->next=newl;   /*设置头结点*/
 }


/* 写出将线性表 l 逆置的算法  方法二 */

/* 此算法的时间复杂度为 T(n)=O(n)*/

void turn2(slink *L)
{
 slink *p,*q,*r;
 p=L->next;
 q=p->next;
 r=NULL;
 while(p!=NULL)
 { L->next=p;
   p->next=r;
   r=p;
   p=q;
   q=q->next;
 }
}

/* 写出将线性表 l 逆置的算法  方法三 */
void turn3(slink *L)
{
 slink *p,*q;
 p=L->next;
 L->next=NULL;
 while(p->next!=NULL)
 { q=p;
   p=p->next;
   q->next=L->next;
   L->next=q;
 }
}


/*编写算法,将带头结点的单链表拆成一个奇数链表和一个偶数链表*/
slink *CF(slink *l)
 {
   slink *ll,*p,*q,*pp;
   p=l->next;
   q=l;
   ll=(slink *)malloc(sizeof(slink));
   ll->next=NULL;
   pp=ll;
   while(p!=NULL)
    {
     while(p!=NULL&&p->data%2!=0) {q->next=p;q=q->next;p=p->next;}
     if(p!=NULL)
       {pp->next=p;pp=pp->next;p=p->next;}
    }
   pp->next=NULL;
   q->next=NULL;
   return ll;
 }

/*升序排序*/
void sort1(slink *l1)
{
 slink *p,*q;
 ElemType r;
 p=l1->next;
 while(p!=NULL)
 { q=p->next;
   while(q!=NULL)
   { if(p->data>q->data)
       { r=p->data;p->data=q->data;q->data=r;}
     q=q->next;
   }
   p=p->next;
 }
}
/* 习题7－4－3 */
void sort2(slink *l1)
{
 slink *p,*q,*r,*s;
 p=l1;
 while(p->next!=NULL)
 { q=p->next;
   r=p;
   while(q->next!=NULL)
   { if(q->next->data<r->next->data)
	r=q;
     q=q->next;
   }
   if(r!=p)
     {s=r->next;
      r->next=s->next;
      s->next=p->next;
      p->next=s;
     }
   p=p->next;
 }
}

/* 习题7－4－4 */
void sort3(slink *l1)
{
 slink *p,*q,*end;
 ElemType r;
 end=l1->next;
 while(end->next!=NULL) end=end->next;
 p=l1->next;
 while(l1->next->next!=end)
 { p=l1->next;q=p->next;
   while(q!=end)
   { if(p->data>q->data)
       { r=p->data;p->data=q->data;q->data=r;}
     p=q;q=q->next;
   }
   end=p;
 }
}

/* 习题7－4－5 */
void sort4(slink *l1)
{
 slink *p,*q,*end,*k;
 ElemType r;
 if(l1->next!=NULL)
 {
  end=l1->next->next;
  l1->next->next=NULL;
  while(end!=NULL)
  { p=l1;q=l1->next;
    while(q->data<end->data&&q!=NULL)
    { p=q;q=q->next;}
    k=end;
    end=end->next;
    p->next=k;
    k->next=q;
  }
 }
}



delp_prior(slink *L,slink *p) /* 习题2－4－2 */
{
 slink *q1,*q2;
 if(p==L||p==L->next||p==NULL)
   printf("\nno exist!");
 else
   { q1=L;q2=L->next;
     while(q2->next!=p)
     { q1=q2;q2=q2->next;}
     q1->next=p;
     free(q2);
   }
}



/* 习题2－4－7*/
CFGL(slink *A,slink *B,slink *C)
 {
   slink *pb,*p,*q,*pc;
   p=A->next;
   q=A;
   while(p!=NULL)  /* 删除值为0的结点 */
     { while(p!=NULL&&p->data!=0)
	 {q=p;p=p->next;}
       if(p->data==0)
	 { q->next=p->next;
	   free(p);
	   p=q->next;
	 }
     }
   B->next=A->next;
   p=A->next;
   pb=B;
   pc=C;
   while(p!=NULL)
    {
     while(p!=NULL&&p->data<0) {pb->next=p;pb=pb->next;p=p->next;}
     if(p!=NULL)
       {pc->next=p;pc=pc->next;p=p->next;}
    }
   pb->next=NULL;
   pc->next=NULL;
 }

/* 习题 2-9 */
/*设计思想:先将单链表A中重复的结点删除,然后对单链表A的每个结点
  判断是否在单链表B或C中,若不在则删除;否则保留.最后的单链表A即为所求*/
  void public(slink *ha,slink *hb,slink *hc)
  { slink *pa,*pb,*pc,*q,*r;
    pa=ha->next;
    while(pa!=NULL&&pa->next!=NULL)
    { q=pa->next;
      if(pa->data==q->data)
      { pa->next=q->next;
	free(q);
      }
      pa=pa->next;
    }
    pa->next=NULL;
    pa=ha->next;
    r=ha;r->next=NULL;
    pb=hb->next;pc=hc->next;
    while(pa!=NULL)
    { while(pb!=NULL&&pa->data>pb->data)
	pb=pb->next;
      while(pc!=NULL&&pa->data>pc->data)
	pc=pc->next;
      if(pa->data==pb->data&&pa->data==pc->data)
      { r->next=pa;
	r=pa;
	pa=pa->next;
	r->next=NULL;
      }
      else
      { q=pa;
	pa=pa->next;
	free(q);
      }
    }
 }

main()
{int i,x;
 slink *l1,*l2,*l;
 l=initlist();      /*初始化单链表l*/

 for(i=1;i<=5;i++)   /*在单链表l1中插入5个结点*/
 {scanf("%d",&x);
  insert(l,x,i);
 }
 printf("\n");
 sort4(l);
 print(l);
 printf("\n");

}





