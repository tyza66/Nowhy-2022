#include<stdio.h>
#include<math.h> 
main()
{
	float a=0,b=0;
	printf("请输入两条边长（a,b）:");
	scanf("%f,%f",&a,&b);
	printf("%f",sqrt(a*a+b*b));
} 