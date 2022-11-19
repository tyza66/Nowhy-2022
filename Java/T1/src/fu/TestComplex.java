package fu;

public class TestComplex {
	public static void main(String[] args) {
		Complex a = new Complex();
		System.out.println(a.toString());
		a.setRealPart(6);
		System.out.println(a.getRealPart());
		a.setImaginaryPart(7);
		System.out.println(a.getImaginaryPart());
		System.out.println(a.toString());
		Complex b = new Complex(3); 
		System.out.println(b.toString());
		a = a.complexAdd(b);
		System.out.println(a.toString());
		a = a.complexAdd(12);
		System.out.println(a.toString());
		Complex c = new Complex(3,8); 
		a = a.complexMinus(c);
		System.out.println(a.toString());
		a = a.complexMinus(8);
		System.out.println(a.toString());
		System.out.println(b.toString());
		a = a.complexMulti(b);
		System.out.println(a.toString());
		a = a.complexMulti(8);
		System.out.println(a.toString());
		System.out.println(a.abs());
	}
}
