#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct
{
	int top;
	ElemType *base;
	int stacksize;
}sqstack;

//初始化 
void initstack(sqstack *S)
{
	S->base = (ElemType *)malloc(100*sizeof(ElemType));
	S->top = 0;
	S->stacksize = 100;
}

//压栈 
int push(sqstack *S,ElemType x){
	if(S->top == S->stacksize){
		S->base = (ElemType *)realloc(S->base,(S->stacksize+1)*sizeof(ElemType));
		if(!S->base) return 0;
		S->stacksize++;
	}
	S->base[S->top++] = x;
	return 1;
}

//弹栈
int pop (sqstack *S,ElemType *x){
	if(S->top == 0) return 0;
	*x = S->base[--(S->top)];
	return 1;
}

//判断栈空 
int empty(sqstack *S){
	if(S->top == 0) return 0;
	return 1;
}

//将任意一个十进制数转化为任意（2～9）进制数
void zhuan(int x,int jinzhi,int *chu){
	sqstack A,*S = &A;
	int i = 0,j = 1,k = 1;
	int temp;
 	initstack(S);
 	while(x!=0)
 	{ 
 		push(S,x%jinzhi); x=x/jinzhi;
	} 
	while(j<S->top) {j++;k*=10;}
	while(S->top != 0){
		pop(S,&temp);
		i += temp*k;
		k /= 10;
	}
	*chu = i;
}
//主函数 
main(){
	int x;
	zhuan(12345,A,&x);
	printf("%d",x);
}
