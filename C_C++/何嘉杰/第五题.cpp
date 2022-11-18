#include<stdio.h>
#include<string.h>
main(){
	int i,sum=0;
	char a[30];
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
	  if(a[i]>='a'&&a[i]<='z')
	  sum+=1;
	  printf("%d",sum);
}
