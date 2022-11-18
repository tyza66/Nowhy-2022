#include<stdio.h>
#include<string.h>
main(){
	char str[90];
	gets(str);
	int i;
	for(i=0;i<strlen(str);i++)
	  if(str[i]!=' ')
	  printf("%c",str[i]);
}
