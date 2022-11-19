package dfasdfsadfasdas;

import java.util.ArrayList;
import java.util.Iterator;


public class ArrayListaa {
	public static void main(String[] args) {
		int i=0;
		ArrayList<String> a = new ArrayList<String>();
		a.add("Aa");a.add("Bb");a.add("Cc");
		System.out.println("圻兵！！！！！！！！！！！！");
		for(i=0;i<3;i++) {
			System.out.println(a.get(i));
		}
		
		System.out.println("沫哈延寄亟！！！！！！！！！！！！");
		for(i=0;i<3;i++) {
			System.out.println(a.get(i).toUpperCase());
		}
		
		System.out.println("亨旗匂延寄亟！！！！！！！！！！！！");
		for(Iterator<String> it = a.iterator();it.hasNext();) {
			String s = it.next();
			System.out.println(s.toUpperCase());
		}

		System.out.println("RA延寄亟！！！！！！！！！！！！");
		 a.replaceAll(e -> e.toUpperCase());
		for(Iterator<String> it = a.iterator();it.hasNext();) {
			String s = it.next();
			System.out.println(s);
		}
	}
}
