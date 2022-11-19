package bao;

public class Tx {

	/*生成10x10字符数组，元素初值·的随机漫步。程序随机从一个元素走到另一个元素，
	 * 每次向上下左右移动一个元素位置，已访问过的用A到Z标记
	 * 一不可走数组外面，二不可走已有字母标记位置，四个方向都堵住程序终止*/
	    public static void main(String[] args) { 
	    	
	    		  int i,j,t=0,a=0,b,c,m;
	    		  char[][]p=new char[10][10];
	    		  //赋元素初值
	    		  for(i=0;i<10;i++)
	    		  for(j=0;j<10;j++)
	    		  {
	    		   p[i][j]='.';
	    		  }
	    		  i=0;j=0;
	    		  //判断方向    0 1 2 3 
	    		  //         上 下 左 右
	    		  //random的值是0.0~1.0,double类型
	    		  //实现在指定的数中进行随机
	    		  int[] nums = { 0,1,2,3 };
	    		  i=(int) (Math.random()*nums.length);
	    		  j=(int) (Math.random()*nums.length);
	    		  p[i][j]='A';
	    		  while(t!=25)
	    		  {
	    		   a=(int) (Math.random()*nums.length);
	    		   while(a==0)//上
	    		   {
	    		    i=i-1;
	    		    if(i>=0&&p[i][j]!='.')
	    		    {
	    		     t++;
	    		     p[i][j]=(char)('A'+t);
	    		    }
	    		    else
	    		     i++;
	    		   }
	    		   while(a==1)//下
	    		   {
	    		    i=i+1;
	    		    if(i<9&&p[i][j]!='.')
	    		    {
	    		     t++;
	    		     p[i][j]=(char)('A'+t);
	    		    }
	    		    else
	    		     i--;
	    		   }
	    		   while(a==2)//左
	    		   {
	    		    j=j-1;
	    		    if(j>0&&p[i][j]!='.')
	    		    {
	    		     t++;
	    		     p[i][j]=(char)('A'+t);
	    		    }
	    		    else
	    		     j++;
	    		   }
	    		   while(a==3)//右
	    		   {
	    		    j=j+1;
	    		    if(j<9&&p[i][j]!='.')
	    		    {
	    		     t++;
	    		     p[i][j]=(char)('A'+t);
	    		    }
	    		    else
	    		     j--;
	    		   }
	    		   if(p[i-1][j]!='.'&&p[i+1][j]!='.'&&p[i][j-1]!='.'&&p[i][j+1]!='.')
	    		   { //堵车
	    		    break;
	    		      }   
	    		 }
	    		  for(i=0;i<10;i++)
	    		  {
	    		   for(j=0;j<10;j++)
	    		   {
	    		    System.out.print(""+p[i][j]+" ");
	    		   }
	    		   System.out.println();
	    		  }
	    }

}
