#include<stdio.h>
#include<string.h>
main()
{
loop:	char a[999],s=0,i=0,ha=0;
	printf("请输入一句话；");
    getchar();
	gets(a); 
	if(a[0]!=' ') s++;
	for(i=0;i<strlen(a)-1;i++)
	{
  		if(a[i]==' '&&a[i+1]!=' ')
  		{
  			s++;
 		}
  	}
  	
  	printf("这句话一共有%d个词 (0退出 1继续)\n",s);
  	scanf("%d",&ha);
  	if(ha) goto loop;
  	else return 0;
}