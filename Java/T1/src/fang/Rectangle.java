package fang;

public class Rectangle {
	private double length;
	private double width;
	
	Rectangle(){
		this(1.0,1.0);
	}
	
	Rectangle(double length,double height){
		this.length = length;
		this.width = height;
	}
	
	public double perimeter() {
		return (width + length)*2;
	}
	
	public double area() {
		return width * length;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
	}
	
	
}
