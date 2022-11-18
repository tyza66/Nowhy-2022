#include<stdio.h>
#include<string.h>
//字母变小写 
int da(int a)
{
	return a-32;
}
//字母变小写 
int xiao(int a)
{
	return a+32;
}
//用来查数判断应该变大还是变小 
int shu(char a[])
{
	int chang = strlen(a) ,x=0,y=0;
	//printf("%d",chang);
	while(chang>0)
	{
		if(a[chang-1]>='A'&&a[chang-1]<='Z') x++;
		if(a[chang-1]>='a'&&a[chang-1]<='z') y++;
		chang--;
	}
	if(x>=y) return 1; else return 0;
} 
//转换函数 
void tihuan(int a,char *b)
{
	while(*b!='\0')
	{
		if(a==1) 
		{
			if(*b>='a'&&*b<='z') *b=da(*b);
		}
		if(a==0)
		{
			if(*b>='A'&&*b<='Z') *b=xiao(*b);
		}
		b=b+1;
	}
}
//主函数 
main()
{
	char z[999];
	printf("请输入要搞的字符串：");
	scanf("%s",&z); 
	tihuan(shu(z),&z[0]);
	printf("%s",z);	
} 
