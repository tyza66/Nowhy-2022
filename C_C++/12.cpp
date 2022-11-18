/* 线性表的链式存储 */
#include "stdlib.h"
#include "stdio.h"
/* 结点类型 */
//#define ElemType int
typedef int ElemType;
#define MAXSIZE 100

typedef struct
	{  ElemType *data;
	   int len;
	   int listsize;
	}sqlist;
	
void initlist(sqlist *L)
{
   L->data=(ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
   L->len=0;
   L->listsize=MAXSIZE;
}

int getlen(sqlist *L)
{
   return(L->len);
}

ElemType getelem(sqlist *L,int i)
{
  if(i>=1&&i<=L->len) return(L->data[i-1]);
}

int locate(sqlist *L,ElemType x)
{
  int i=0;
  while(i<L->len&&L->data[i]!=x) i++;
  if(i>=L->len) return -1;
  else return i+1;
}

int insert(sqlist *L,ElemType x,int i)
{
  int j;
  if(i<1||i>L->len+1)
    return 0;
  if(L->len==L->listsize)
    L->data=(ElemType *)realloc(L->data,(L->listsize+1)*sizeof(ElemType));
    
  	for(j=L->len-1;j>=i-1;j--)
      L->data[j+1]=L->data[j];
      
    L->data[i-1]=x;
    L->len++;
    return i;
}

int del(sqlist *L,int i)
{
  int j;
  if(i<1||i>L->len)
    return 0;
  else
    { 
		for(j=i;j<=L->len-1;j++)
			L->data[j-1]=L->data[j];
			
		L->len--;
		return i;
    }
}

void print(sqlist *L)
{
  int i;
  for(i=1;i<=L->len;i++)
    printf("%d  ",L->data[i-1]);
  printf("\n");
}

void move(sqlist *L)
{
 int i=0,j=L->len-1;
 ElemType temp;
 while(i<j)
   { while(L->data[i]%2==1&&i<=L->len-1) i++;
     while(L->data[j]%2==0&&j>=0) j--;
     if(i<j)
       { temp=L->data[i];
	 L->data[i]=L->data[j];
	 L->data[j]=temp;
       }
   }
}

void merge(sqlist *L1,sqlist *L2,sqlist *L)
{
  int i=0,j=0,k=1;
  while(i<L1->len&&j<L2->len)
    if(L1->data[i]<L2->data[j])
      {insert(L,L1->data[i],k);k++;i++;}
    else
      {insert(L,L2->data[j],k);k++;j++;}
      
  while(i<L1->len)
      {insert(L,L1->data[i],k);k++;i++;}
      
  while(j<L2->len)
      {insert(L,L2->data[j],k);k++;j++;}
}

void a_b(sqlist *L1,sqlist *L2,sqlist *L3)/* 习题2－4－1 */
{
  int i=0,j,k=0;
  while(i<L1->len)
  { j=0;
    while(j<L2->len&&L1->data[i]!=L2->data[j]) j++;
    if(L1->data[i]==L2->data[j])
      L3->data[k++]=L1->data[i];
    i++;
  }
  L3->len=k;
}


void delxtoy(sqlist *L,ElemType x,ElemType y) /* 习题 2－4－4 */
{ int k=0,i=0;
  while(i<L->len)
  { if(L->data[i]>=x&&L->data[i]<=y)
      k++;
    else
      L->data[i-k]=L->data[i];
    i++;
  }
  L->len-=k;
 }

main()
{
 int i,x;
 sqlist L,L1,L2;
  initlist(&L1);
 for(i=1;i<=5;i++)
 {
 	scanf("%d",&x);
    insert(&L1,x,i);
 }
 print(&L1);
 
 initlist(&L2);
 for(i=1;i<=4;i++)
 {
 	scanf("%d",&x);
    insert(&L2,x,i);
 }
 print(&L2);

 initlist(&L);
 merge(&L1,&L2,&L);
 print(&L);

 
 /*printf("%d\n",x);
 delete(&L,2);
 print(&L);
 merge(&L1,&L2,&L);
 print(&L);
 move(&L);*/
 //print(&L1);
 //delxtoy(&L1,2,3);
 //print(&L1);
}
