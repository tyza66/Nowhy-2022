#include<stdio.h>
#include<stdlib.h>
void yu(char *ch1){
	int i,j=0,k;
	for(i=0;ch1[i]!='\0';i++){
		if(ch1[i]!=' '&&ch1[i]!='\0'){
			ch1[j]=ch1[i];
			j++;}

		
	}

	ch1[j]='\0';



}
main(){
	int i,j;
	char ch1[100];
//	char ch1[]="sada s f sdf";
	gets(ch1);
	yu(ch1);

	printf("%s",ch1);
		



}

