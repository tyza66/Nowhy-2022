package aasa;
import java.util.Scanner;

public class ExceptionTest2 {
	public static void main(String[] args) {
		Scanner c = new Scanner(System.in);
		double a = 0;
		System.out.print("请输入要计算的半径：");
		try{
			a = c.nextDouble();
			System.out.print("面积是："+Math.PI*a*a);
		}catch(Exception e) {
			System.out.print("您输入的数值不合法");
		}
		
	}
}
