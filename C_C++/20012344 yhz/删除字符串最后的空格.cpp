#include<stdio.h>
#include<stdlib.h>
main(){
	char a[60]="sad jhjk    ";
	char *p;
	p=a;
	while(*p!='\0')
	p++;p--;
	while(*p==' ')
	p--;p++;


	*p='\0';
	printf("%s",a);


}

