package sdhjasvbdhugawjdik;

public class Point <T>{
	private T x;
	private T y;
	
	public Point(T x,T y) {
		this.x = x;
		this.y = y;
	}
	public T getX() {
		return x;
	}
	public void setX(T x) {
		this.x = x;
	}
	public T getY() {
		return y;
	}
	public void setY(T y) {
		this.y = y;
	}
	
	public void translate(T x,T y) {
		this.x = x;
		this.y = y;
	}
	
	public String toString() {
		return "x="+x+",y="+y;
	}
	
	public static void main(String[] args) {
		Point<Integer> a = new Point<Integer>(2,3);
		Point<Double> b = new Point<Double>(1.5,2.5);
		System.out.println(a);
		System.out.println(b);
		a.translate(3, 4);
		System.out.println(a);
	}
}
