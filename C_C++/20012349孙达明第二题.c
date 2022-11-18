//输出5x5对角线的对角线
#include<stdio.h>
#define N 5
void duijao(int a[N][N])
{
    int i,j,s1=0,s2=0;
	printf("主对角线的值和总和分别为：");
	for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            //主
           
            if(i == j) 
            {
                printf("%d,",a[i][j]);
                s1+=a[i][j];	
            }
        }
		printf("主总和：%d \n",s1);
		printf("次对角线的值和总和分别为：");
		for(i=0;i<N;i++)
        	for(j=0;j<N;j++)
       	 {
     	     //次 
           
       	     if(i+j == N-1) 
       	     {
                printf("%d,",a[i][j]);
                s2+=a[i][j];	
          	 }
         }
    printf("次总和：%d \n",s2);
}
main()
{
    int i,j,a[N][N];
    printf("请输入5*5数组个单元格的元素");
     for(i=0;i<N;i++)
    	for(j=0;j<N;j++)
			{
				scanf("%d",&a[i][j]);
			}  
	for(i=0;i<N;i++)
	{ 
    	for(j=0;j<N;j++)
			{
				printf("%d\t",a[i][j]);
			} 
	printf("\n"); 
	} 
    duijao(a);
}

