//删除字符串尾部空格 
#include<stdio.h>
#include<string.h>
main()
{
	int i,j=0,g=0,f=2;
	char a[999];
	printf("请输入一个需要去掉尾部空格的字符串：");
	gets(a);
	printf("您输入的原来是“%s”，",a);
	if(a[strlen(a)-1] == ' ')
	{ 
		for(i=0;i<strlen(a);i++)
		{
		     if(a[i] == ' ' )  
		     {
		     	if(j==1) break;
	 	     j=1; 
			  g=i;
		     }

  	   		 if(a[i] != ' ') j=0;
		}
		if(j==1)a[g] = '\0' ;
	}
	printf("去掉尾部空格后是“%s”\n",a);
}
 
