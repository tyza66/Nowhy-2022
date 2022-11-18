#include<stdio.h>
void fun1(int b[66])
{
	int a[10],i;
	for(i=0;i<10;i++)
	a[i]=b[9-i];
	for(i=0;i<10;i++)
	printf("%d,",a[i]);
	printf("\n",a[i]);
} 
void fun2(int b[66])
{
	int a=9,b1=0,t,i;
	while(b1<a)
	{t=b[b1];  b[b1]=b[a]; b[a]=t;
	a--;b1++;
	}
	for(i=0;i<10;i++)
	printf("%d,",b[i]);
}
main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10},b[]={1,2,3,4,5,6,7,8,9,10};
	fun1(a); 
	fun2(b);
}
