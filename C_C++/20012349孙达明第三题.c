//输出杨辉三角前十行 
#include<stdio.h>
#define N 10
void yh(int n)
{
	int i,j,a[N][N];
	 for(i=0;i<n;i++)
	 	for(j=0;j<=i;j++) 
	 	{
	 		if(i==j||j==0) a[i][j] = 1;
	 		if(j>0&&i>j)
	 		a[i][j] = a[i-1][j-1]+a[i-1][j];
  		}
     for(i=0;i<n;i++)
     {
     	for(j=0;j<=i;j++) 
	 	{
	 	printf("%d\t",a[i][j])	;
  		}
  		printf("\n");
      }
} 
main()
{
	yh(N);
}
