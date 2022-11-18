#include<stdio.h>

void fun(char *w,char x,int *n)
{
	int i = 0,t,j;
	while(w[i]>x  &&  i<=*n) i++;
	t = w[i];
	for(j=i;w[j]!='\0';j++)
	{
		w[j] = t;
		t = w[j+1];
	}
}

main()
{
	int i,m;
	char a[6]={'a','b','c','e','f'};
	m=5;
	fun(a,'d',&m);
	for(i=0;i<6;i++)
	printf("%c",a[i]);
}
