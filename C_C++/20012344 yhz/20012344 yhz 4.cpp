#include<stdio.h>
#define N 10
main(){
	int i,j,k;
	int a[N][N];	

	for(i=0;i<N;i++){	  

	  for(j=0;j<N+1;j++){
		a[i][0]=1;
	  	a[i][i]=1;
	  	a[i][j]=a[i-1][j-1]+a[i-1][j];
	  }
	}
	for(i=0;i<N;i++){
	  for(j=0;j<=i;j++){
	   printf("%4d",a[i][j]);
	  }
	  printf("\n");
	}
	
	
	






}

