//矩阵（5X5）转置并输出 
#include<stdio.h>
#define N 5
void zz(int a[N][N])
{
	int i,j,t;
	for(i=0;i<N;i++)
		for(j=0;j<i;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;	
		} 
}
main()
{
	int s[N][N],i,j;
	printf("请输入25个数组元素"); 
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				scanf("%d",&s[i][j]);
			} 
			
		for(i=0;i<N;i++)
		{ 
			for(j=0;j<N;j++)
				printf("%d\t",s[i][j]);
			printf("\n"); 
		} 
	zz(s);
	printf("\n");
		for(i=0;i<N;i++)
		{ 
			for(j=0;j<N;j++)
				printf("%d\t",s[i][j]);
			printf("\n"); 
		} 
}


