#include<stdio.h>
main()
{
	int a,g,s,b,i;
	printf("请输入一个三位数值：");
	scanf("%d",&a);
	g=a%10;
	s=(a%100)/10;
	b=a/100;
	printf("各位数字之和是%d\n",g+s+b);
	if(a%17 == 0) printf("能被17整除\n");
	else  printf("不能被17整除\n");
	for(i=100;i<=999;i++)
	{
		a=i;
		g=a%10;
		s=(a%100)/10;
		b=a/100;
		if(g*g*g+s*s*s+b*b*b==a) printf("%d,",a);
	}
}
