#include<stdio.h>
#include<string.h>
main()
{
    FILE *fp1,*pf2;
    char *p,*q;
    char t;
    char ch[60];
	p=q=ch;
    if ((fp1=fopen("file1.txt","r"))==NULL)
    {
        exit(0);
    }
    if ((fp1=fopen("file2.txt","r"))==NULL)
    {
        exit(0);
    }
    fgets(ch,99,fp1);
    while(*q!='\0') q++;
    whlie(p<=q)
    {
    	t=*p;
    	*p=*q;
    	*q=t;
    	p++;q--;
    }
    puts(ch);
    fclose(fp1);
}