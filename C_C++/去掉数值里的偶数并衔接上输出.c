//È¥µôÅ¼Êı 
#include<stdio.h>

int f = 0;
int ci(int a,int b)
{
	int i;
	for(i=0;i<=b;i++) a*=10;
	return a;
}
int qu(int a)
{
	int n=0,c;
	while(a != 0)
	{
	c = a%10;
		if(c%2 != 0) 
		{
			f+=ci(c,n);
			n++;
		}
		a/=10;
	
	}	return f/10;
} 
main()
{
	int a = 13214596;
	printf("%d",qu(a));
} 
