package gh;

public class WildDuck extends Animal implements Swimmable,Flyable{
	public static void main(String[] args) {
		Swimmable a= new WildDuck();
		Flyable b= new WildDuck();
		Animal c= new WildDuck();
		a.swim();
		b.fly();
		c.eat();
	}
	@Override
	void eat() {
		System.out.println("I am eating!");
	}
	
	public void swim() {
		System.out.println("I am swimming!");
	};
	public void fly() {
		System.out.println("I am swimming!");
	};
}
