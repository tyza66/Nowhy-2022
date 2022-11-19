package fang;

public class TestRectangle {

	public static void main(String[] args) {
		Rectangle a1 = new Rectangle();
		System.out.println(a1.area());
		System.out.println(a1.perimeter());
		a1.setLength(1.2);
		a1.setWidth(1.5);
		System.out.println(a1.getLength());
		System.out.println(a1.getWidth());
		
		Rectangle a2 = new Rectangle(5.0,6.0);
		System.out.println(a2.area());
		System.out.println(a2.perimeter());
		a2.setLength(1.2);
		a2.setWidth(1.5);
		System.out.println(a2.getLength());
		System.out.println(a2.getWidth());
	}

}
