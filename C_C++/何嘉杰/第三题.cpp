#include<stdio.h>
#define N 10
main(){
	int a[N][N],i,j;
	for(i=0;i<10;i++)
	for(j=0;j<=i;j++)
	if(j==0||j==i)a[i][j]=1;
	else a[i][j]=a[i-1][j]+a[i-1][j-1];
	for(i=0;i<10;i++)
	{for(j=0;j<=i;j++)
	   printf("%4d",a[i][j]);
	 printf("\n");
	}
}
