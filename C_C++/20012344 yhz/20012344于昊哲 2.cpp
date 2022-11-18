#include<stdio.h>
#define N 5
main(){
	int i,j,k,t;
	int a[5][5],b[5][5];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&a[i][j]);
			}
	
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
		b[i][j]=a[j][i];
		
		
		}
		}
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
			{
					printf("%4d",b[i][j]);
					
			
			}
			printf("\n");
		
		
		}

	 







}

