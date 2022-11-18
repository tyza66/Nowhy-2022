package bao;

import java.util.Arrays;

public class SourceTest {

	public static void main(String[] args) {
		int a;
		int[] source = new int[] {1,2,3,4,5};
		int[] target = new int[5];
		for(int i:source) {
			System.out.print(i);	
		}System.out.println("");
		for(a = 0;a < source.length;a++) {
			target[a] = source[a];
		}
		for(int i:target) {
			System.out.print(i);
		}System.out.println("");
		target = new int[5];
		for(int i:target) {
			System.out.print(i);
		}System.out.println("");
		System.arraycopy(source, 0, target, 0, 5);
		for(int i:target) {
			System.out.print(i);
		}System.out.println("");
		target = new int[5];
		for(int i:target) {
			System.out.print(i);
		}System.out.println("");
		target = Arrays.copyOf(source, 5);
		for(int i:target) {
			System.out.print(i);
		}System.out.println("");
	}
}
