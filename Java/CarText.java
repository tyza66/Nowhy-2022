package Text1;

public class CarText {

	public static void main(String[] args) {
		Car car1 = new Car();
		Car car2 = new Car();
		Car car3 = new Car();
		Car car4 = new Car();
		double x = car1.getPrice();
		System.out.println(x);
		car1.setPrice(200.2);
		x = car1.getPrice();
		System.out.println(x);
		String s = car1.getModel();
		System.out.println(s);
	}

}
