package dcvzd;

import java.util.HashSet;
import java.util.Iterator;

public class Df {

	public static void main(String[] args) {
		String a = "You can say that again! again! You said it!";
		HashSet<String> hashSet = new HashSet<String>();
		String[] aIn = a.split(" ");
		String[] out = new String[99];
		for(String d:aIn) {
			if(!hashSet.contains(d))
				hashSet.add(d);
			else
			{
				System.out.println("重复："+d);
				out[out.length-1] = d;
			}
		}
		System.out.println("不同的单词有"+hashSet.size()+"个，分别是：");
		for(Iterator<String> it = hashSet.iterator();it.hasNext();) {
			String s = it.next();
			System.out.println(s);
		}
	}

}
