package sa;

public class Sample3 {
	private static String name;
	public Sample3() {
		name = "苹果";
	}
	static class Apple{
		int innerPrice = 0;
		public Apple(int price) {
			innerPrice = price;
		}
		public void introducrion() {
			System.out.println("这是一个"+name);
			System.out.println("它的零售单价为："+innerPrice+"元");
		}
	}
	public static void main(String[] args) {
		Sample3.Apple apple = new Sample3.Apple(8);
		apple.introducrion();
		Sample3 sample = new Sample3();
		Sample3.Apple apple2 = new Sample3.Apple(10);
		apple2.introducrion();
	}
}
