//小写字符转换成一个大写字符 
#include<stdio.h>
main()
{
	char a,b; 
	printf("请输入你要转换的小写字符：");
	scanf("%c",&a);
	if(a>=97 && a<=122)
	{
		b = a-('a'-'A'); //或者直接减去32
		printf("%c转换成大写是%c\n",a,b) ;
	}
	else printf("error!");
} 
 
