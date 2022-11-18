#include<stdio.h>
main(){
	char str[80],*p;
	gets(str);
	p=str;
	while(*p) p++;
	p--;
	while(*p==' ') p--;
	p++;
	*p='\0';
	printf("%s",str);
}
