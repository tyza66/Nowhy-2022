//tongjixiaoxiezimu
#include<stdio.h>
#include<stdlib.h>
main(){
	int i,j,k=0;
	char ch1[100];
//	char ch1[100]="fsdusudsdfYHJDKHFJ";
	gets(ch1);
	j=strlen(ch1);

		for(i=0;i<=j;i++){
			if(ch1[i]>='a'&&ch1[i]<='z'){
				k++;}
			
			}
			printf("%d",k);
	




}

