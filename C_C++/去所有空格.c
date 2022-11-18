#include<stdio.h>
main()
{
	int i,j;
	char a[80]="a b c d";
	for(i=j=0;a[i]!='\0';i++)
		if(a[i] != ' ') 
		{ 
			a[j]=a[i]; 		j++;
		}
	
	 a[j]='\0'; 
	 printf("%s",a);
} 
