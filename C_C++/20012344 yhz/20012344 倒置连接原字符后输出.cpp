#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(){
	char ch2[100];
	int i,j,k;
	char ch1[]="sadhj jasdhk";
	strcpy(ch2,ch1);
	k=strlen(ch1) ;
	for(i=0;i<=k;i++){
		ch2[i]=ch1[k-1-i];
	
	}
	strcat(ch1,ch2);
	ch1[2*i]='\0';
	printf("%s",ch1);



}

