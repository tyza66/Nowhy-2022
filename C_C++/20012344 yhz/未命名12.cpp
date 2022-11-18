#include<stdio.h>
int yu(int *x,int *y){
	int k;
	k=*x;
	*x=*y;
	*y=k;
	return *x,*y;


}
main(){
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	yu(&a,&b);
	printf("%d %d",a,b);

}
