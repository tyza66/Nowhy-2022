package sa;

public class Test {

	public static void main(String[] args) {
		Sample sample = new Sample();
		Sample.Inner inner = sample.new Inner();
		
		Sample.Inner inner1 = new Sample().new Inner();
		inner.print();
		inner1.print();
	}

}
