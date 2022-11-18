#include<stdio.h>
#define N 5
main(){
	int i,j,a[N][N],t;
	for(i=0;i<N;i++)
	 {for(j=0;j<N;j++)
	    scanf("%d",&a[i][j]);}
    for(i=1;i<N;i++)
      {for(j=0;j<i;j++)
      {t=a[i][j];a[i][j]=a[j][i];a[j][i]=t;}}
    for(i=0;i<N;i++)
    {for(j=0;j<N;j++)
    	{
        printf("%5d",a[i][j]);
    	}
        printf("\n");
    }
}
