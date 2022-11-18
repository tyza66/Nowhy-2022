package gh;

public class WildDuckTest {
	public static void main(String[] args) {
		Swimmable a= new WildDuck();
		Flyable b= new WildDuck();
		Animal c= new WildDuck();
		a.swim();
		b.fly();
		c.eat();
	}
}
