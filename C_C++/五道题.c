#include<stdio.h>
#include<string.h>
//输出这个句话有几个单词 
void cishu()
{
	char a[100],c;
	int i = 0,word = 0,s = 0;
	printf("请输入一句话:");
	gets(a); 
	for(i=0;(c=a[i]) != '\0';i++)
	{
		if(a[i] == ' ') word = 0;
		else if(word == 0 )
		{
			word = 1;
			s++;
		}
	}
	printf("这句话一共有%d个词\n",s);
}
//利用另一个数组输出字符串逆置存放并输出
void jianjie()
{
	char a[999],b[999];
	int i = 0; 
	printf("请输入要逆序的字符:");
	gets(a); 
	for(i=0;i<strlen(a);i++) 
	b[strlen(a)-1-i] = a[i];
	puts(b); 
}  
//利用数组自身输出字符串逆置存放并输出
void zhijie()
{
	char a[999],temp[999];
	int i = 0; 
	printf("请输入要逆序的字符:");
	gets(a); 
	for(i=0;i<strlen(a);i++) 
	temp[strlen(a)-1-i] = a[i];
	strcpy(a,temp); 
	puts(a); 
}  
//将一个字符串逆置后接到原串的后面并输出
void nijie()
{
	char a[999],b[999];
	int i = 0; 
	printf("请输入要逆序的字符:");
	gets(a); 
	for(i=0;i<strlen(a);i++) 
	b[strlen(a)-1-i] = a[i];
	strcat(a,b);
	puts(a); 
}  
//将字符数组a中的字符串复制到字符数组b。	
void copy1()
{
	char a[999],b[999];
	int i = 0; 
	printf("请输入要逆序的字符:");
	gets(a); 
	strcpy(b,a);
	puts(b); 
}  
//统计用户输入的字符串中有多少个'q'字符
void tj()
{
	char a[999];
	int i = 0 , s = 0; 
	printf("请输入要逆序的字符:");
	gets(a); 
	for(;i<strlen(a);i++)
	if(a[i]=='q') s++;
	printf("一共有%d个q",s);
}  
main()
{
	//jianjie(); 
	//zhijie(); 
	//nijie(); 
	//copy1();
	//tj();
	cishu();
} 

