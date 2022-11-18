//统计用户输入的字符串中小写字母的个数 
#include<stdio.h>
#include<string.h>
main()
{
	int i,s=0;
	char a[999];
	printf("请输入一个需要统计的字符串：");
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>='a' && a[i]<='z') s++; //判断条件还可以是 a[i]>=97 && a[i]<=122
	}
	printf("一共有%d个小写字母\n",s);
	 
} 
