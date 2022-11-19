package AA;

public class ProductTest {

	public static void main(String[] args) throws CloneNotSupportedException {
		Product a = new Product(1,"东西","联想",2.5);
		Product b = new Product(1,"东西","联想",2.5);
		Product c = (Product)a.clone();
		c.setId(2);
		System.out.println(a);
		System.out.println(a.getId());
		System.out.println(c);
		System.out.println(c.getId());
		System.out.println(a.equals(b));
		System.out.println(a.hashCode());
		System.out.println(a.toString());
	}

}
