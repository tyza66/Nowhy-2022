#include<stdio.h>
main(){
    char str[81];
	int i,j;
	gets(str);
	i=0;
	while(str[i]!='\0')i++;
	j=i;
	i--;
	while(i>=0) 
	{str[j]=str[i];
	i--;
	j++;
	}
	puts(str);
}
