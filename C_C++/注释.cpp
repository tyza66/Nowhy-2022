/*求Sn=a+aa+aaa+...+aa...a(最后一项n个a)的值，
  其中，a代表一个数字，a和n由用户从键盘输入。*/
  #include<stdio.h>
  int add(int a,int n)  //作用是生成了一个符合格式的值  所以调用它的时候要把它生成的数加起来  这里定义函数的虚参要说明类型 
  {
  	int i=1,sn=0,m=0,j; //这里要让i初始化为1 
  	for(j=1;j<=n;j++) //循环变量不要和位权（个十百千......） 乘的数用一个 
  	{
  		//m+=a*i;   //这里的m没有必要 因为要生成格式的数 只要 1+10+100+.....就行  
  		sn+=a*i;
  		i=i*10; 
	  }	
	return sn;  //这里返回的sn是其中一个aaaa（n个a） 
  } 
  main()
  { 
  	int a,n,i,m,sn=0;//m为累加的数，sn为累加的和 
  	printf("请输入1-10中任意整数a：");
  	scanf("%d",&a);
	printf("请输入1-10中任意整数n：");   
  	scanf("%d",&n);
  	for(i=1;i<=n;i++)   //这个循环的作用是调用上面的函数 得到的值加起来 
	sn+=add(a,i);
  	printf("Sn=a+aa+aaa+...+aa...a(最后一项n个a)的值为%d",sn);
  }