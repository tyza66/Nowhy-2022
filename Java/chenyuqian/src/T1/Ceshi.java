package T1;

import java.util.Scanner;
import java.awt.*;

public class Ceshi {

		public static void main(String[] args) {
			// TODO Auto-generated method stub
			int a=(int)(Math.random()*101)+100;
			System.out.println("请输入你猜的数");
			Scanner sr= new Scanner(System.in);
			int b=(int)sr.nextDouble();
			
			while(a!=b) {
				if(b>a) System.out.println("太大了");
			else System.out.println("太小了");
				 b=(int)sr.nextDouble();
			}
			 System.out.println("答对了");
		}


	
	//第一题-从键盘输入成绩 要求用switch判断成绩分级
	public static int ti1() {
		int a;
		Scanner sc = new Scanner(System.in);
		System.out.print("请在此出入您的成绩：");
		a = sc.nextInt();
		if(a < 0 || a>100)
		{
			System.out.println("您输入的成绩不合法！");
			return 0;
		}
		switch(a/10) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5: System.out.println("不及格！"); break;
			case 6: System.out.println("及格！"); break;
			case 7: System.out.println("中等！"); break;
			case 8: System.out.println("良好！"); break;
			case 9:
			case 10: System.out.println("优秀！"); break;
		}
		return 0;
	}
	
	//第二题-随机产生一个100-200的整数，让用户猜
	public static void ti2() {
		int a =(int)(Math.random()*101)+100,b;
		Scanner sc = new Scanner(System.in);
		System.out.print("请猜数：");
		b = sc.nextInt();
		while(a != b)
		{
			if(b < a) System.out.println("小了！");
			else System.out.println("大了！");
			System.out.print("继续：");
			b = sc.nextInt();
		}
		System.out.println("恭喜你！");
	}
	
	//第三题-接收用户输入的10个数 得到其中的最大值和最小值 要求用do—whlie
	public static void ti3() {
		int a,b = 1,max = 0,min = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("清输入10个数：");
		do {
			a = sc.nextInt();
			if(b == 1) max = min = a;
			if(max < a) max = a;
			if(min > a) min = a;
			b++;
		}while(b <= 10);
		System.out.println("最大值是："+max+",最小值是："+min);
	}
	
	//第四题-上一题用for语句实现
	public static void ti4() {
		int a,b = 1,max = 0,min = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("清输入10个数：");
		for(;b<=10;b++) {
			a = sc.nextInt();
			if(b == 1) max = min = a;
			if(max < a) max = a;
			if(min > a) min = a;
		}
			System.out.println("最大值是："+max+",最小值是："+min);
	}
	
	//第五题-给小孩弄一位数加法题
	public static void ti5() {
		int a = 0,b = 0,c;
		char d;
		Scanner sc = new Scanner(System.in);
		while(true) {
			a = (int)(Math.random()*10);
			b = (int)(Math.random()*10);
			System.out.print(""+a+"+"+b+"=");
			c =sc.nextInt();
			if(c == a + b) System.out.println("答对了！");
			else System.out.println("答错了！");
			System.out.println("继续吗？（y/n）");
			sc.nextLine();
			d = sc.nextLine().charAt(0);
			if(d == 'n') break;
		}
	}
}
