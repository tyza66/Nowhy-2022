#include<stdio.h>
void fun(char *w,char x, int *n){
	int i,p;
	p=0;
	while(x>w[p])	p++;
	for(i=*n-1;i>=p;i--)
		w[i+1]=w[i];
		w[p]=x;
		(*n)++;	


}
main(){
	char str[81]="sbcefg";
	char c='f';
	int n=strlen(str);
	int *p=&n;
	fun(str,c,p);
	puts(str);




}

