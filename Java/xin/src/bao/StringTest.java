package bao;

import java.util.Scanner;

public class StringTest {

	public static void main(String[] args) {
		String a;
		Scanner in = new Scanner(System.in);
		System.out.print("请输入一个字符串：");
		a = in.nextLine();
		System.out.print("字符串长度是："+a.length()+",第一个字符是："+a.toCharArray()[0]+",最后个字符是："+a.toCharArray()[a.length()-1]+",转换成大写是："+a.toUpperCase());
	}
}
