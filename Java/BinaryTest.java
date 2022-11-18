package bao;

public class BinaryTest {

	public static void main(String[] args) {
		System.out.println(toBinary(10));
	}

	public static String toBinary(int value) {
		String a = new String();
			while(value != 0) {
				if(value%2 == 1) {
					value--;
					a = "1" + a;
					value = value/2;
				}else {
					a = "0" + a;
					value = value/2;
				}
			}
		return a;
	}
}
