package bao;

import java.util.Scanner;

public class CircleTest {

	public static void main(String[] args) {
		Scanner a = new Scanner(System.in);
		System.out.printf("°ë¾¶£º");
		double b = a.nextDouble();
		System.out.printf("Ãæ»ýÊÇ£º%.2f",b*b*Math.PI);
	}

}
