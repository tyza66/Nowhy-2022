
#include<stdio.h>
int a1=2;
int f(int n)
{ static int a2=3;
  int t=0;
  
  if(n%2){ static int a3=4; t+=a3++;}
  else { static int a4=5; t+=a4++;}
  
  return t+a2++;
}
main()
{ int s=a1,i;
  for(i=0;i<3;i++) s+=f(i);
  printf("%d\n",s);
}