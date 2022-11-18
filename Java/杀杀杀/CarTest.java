package giao1;

public class CarTest {

	public static void main(String[] args) {
		Car car1 = new Car();
		System.out.println(Car.PrintCounter());
		Car car2 = new Car();
		System.out.println(Car.PrintCounter());
		Car car3 = new Car();
		System.out.println(Car.PrintCounter());
		Car car4 = new Car();
		System.out.println(Car.PrintCounter());
		Car car5 = new Car("±¦Âí",30,2020,80);
		Car car6 = new Car("°ÂµÏ");
		Car car7 = new Car("±¼³Û",30,2020);
		
		double x=car1.getPrice();
		System.out.println(x);
		
		car1.setPrice(30.87);
		x=car1.getPrice();
		System.out.println(x);
		
		String s=car1.getModel();
		System.out.println(s);		
		
		s=car5.getModel();
		System.out.println(s);
		
		s=car6.getModel();
		System.out.println(s);
		
		s=car7.getModel();
		System.out.println(s);
		System.out.println(Car.PrintCounter());
		
		car4.qidong();
		System.out.println(car4.getSpeed());
		car4.speedUp();
		System.out.println(car4.getSpeed());
		car4.speedUp();
		car4.speedUp(100);
		System.out.println(car4.getSpeed());
		car4.speedDown();
		System.out.println(car4.getSpeed());
		car4.stop();
		System.out.println(car4.getSpeed());
		car4.print();
		System.out.println(car4.toString());
	}

}
