#include<stdio.h>
main()
{
	char a[999],t;
	int i,j,k,n = 0;
	gets(a);
	for(i=0;a[i]!='\0';i++) n++;
	for(i=0;i<n-1;n--,i++)
	{
		t=a[i];a[i]=a[n-1];a[n-1]=t;		
	}
	puts(a);
}
