#include<stdio.h>
#define N 5
main(){
	int i,j,k,sum=0;
	int a[N][N];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j) sum+=a[i][j];
		}
	}
	printf("%d",sum);




}
