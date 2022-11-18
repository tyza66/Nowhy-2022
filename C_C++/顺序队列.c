
/* 循环队列顺序存储 */
#include "stdio.h"

#define MAXCSIZE 100
typedef int ElemType;
typedef struct {
  int *base;
  int front;
  int rear;
}cqueue;

/* 建立一个空的循环队列 */

void initqueue(cqueue *cq)
{
 cq->base=(int *)malloc(MAXCSIZE*sizeof(int));
 cq->front=0;
 cq->rear=0;
}

/* 写出在循环队列cq中插入元素e的算法 */

insert(cqueue *cq,ElemType e)
{
 if((cq->rear+1)%MAXCSIZE==cq->front)
   return 0;
 else
 {
  cq->base[cq->rear]=e;
  cq->rear=(cq->rear+1)%MAXCSIZE;
  return 1;
 }
}

/* 写出在循环队列cq中删除元素的算法 */

delete(cqueue *cq,ElemType *e)
{
 if(cq->front==cq->rear)
   return 0;
 else
  {
  *e=cq->base[cq->front];
   cq->front=(cq->front+1)%MAXCSIZE;
   return 1;
  }
}

/* 取队头元素的算法 */

gethead(cqueue *cq,ElemType *e)
{
 if(cq->front==cq->rear)
   return 0;
 else
  {*e=cq->base[cq->front];return 1;}
}

/* 写出输出循环队列cq的算法 */

void print(cqueue *cq)
{
  int i=cq->front;
  while(i!=cq->rear)
  {
   printf("%4d",cq->base[i]);
   i=(i+1)%MAXCSIZE;
  }
}
/* 写出输出循环队列长度的算法 */

length(cqueue *cq)
{
 return((cq->rear-cq->front+MAXCSIZE)%MAXCSIZE);
}

fun()
{
 cqueue cq;
 ElemType x;
 int i;
 initqueue(&cq);
 while(1)
   { scanf("%d",&x);
     if(x>0)
       { i=insert(&cq,x);
	 if(i==0) { printf("stack full\n");exit(0);}
       }
     else if(x<0)
	    {i=delete(&cq,&x);
	     if(i==0)  { printf("stack null\n");exit(0);}
	    }
	  else break;
   }
 print(&cq);
}


main()
{
 /*int i,e;
 cqueue cq;
 initqueue(&cq);
 for(i=6;i<=10;i++)
 insert(&cq,i);
 print(&cq);
 e=length(&cq);
 printf("length=%d\n",e);
 gethead(&cq,&e);
 printf("%d\n",e);
 for(i=1;i<=2;i++)
 delete(&cq,&e);
 e=length(&cq);
 printf("length=%d\n",e);
 print(&cq);*/
 fun();

}

