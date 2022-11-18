#include<stdio.h>
int kankan(int n)
{
	int b = 2;
	if(n == 1) return 0;
	for(;b <= n-1;b++)
	{
		if(n%b == 0) return 0;
	}
	return 1;
}
int pd(int a)
{
	int i;
	for(i=1;i <= a/2 + 1;i++)
	{
		if(kankan(i) && kankan(a-i))
		{
			printf("%d=%d+%d ",a,i,a-i);
			break;
		}
	}
} 
main()
{
	int shu = 0;
	printf("请输入要弄的偶数:");
	scanf("%d",&shu);
	if(shu%2 != 0) 
		{
			printf("别扯，你输入的根本不是偶数！");
			return 0; 
		}
	if(shu > 2)
	{
		pd(shu);
	}
	else printf("超出范围！");
		
}