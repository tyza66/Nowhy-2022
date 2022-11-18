#include<stdio.h>
main(){
	int a[10],i,j,k;
	for(i=0;i<10;i++){
	scanf("%d"&i);
	}
	for(i=0,j=9;i<j;i++,j--)
	{t=a[i];a[i]=a[j];a[j]=t;}
	for(i=0;i<10;i++)
		printf("%4d",a[i]);
	
	


}

