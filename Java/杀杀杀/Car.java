package giao1;

public class Car {// 公共类
	// 成员变量：private
	/*
	 * public String model;//品牌，公共 double price;//包可访问的 private int year;//私有成员，本类
	 * protected double speed;//保护成员：本类、Car的子类
	 */
	private String model;// 实例变量：品牌，公共
	private double price;// 包可访问的
	private int year;// 私有成员，本类
	private double speed;// 保护成员：本类、Car的子类
	public static int counter = 0;//静态成员变量，所有对象共享 看成是类的属性 叫静态成员变量 或者类变量
	//对象名和类名访问均可！！！！！
	//实例变量必须用对象名访问
	
	public static int PrintCounter() { //静态成员方法也叫类方法，通过类名对象名都可以访问,建议用类名访问 只能访问静态变量和静态方法
		//实例方法只能通过对象名访问 实例变量，类方法，实例方法，类方法
		return counter;
	}
	
	/*
	//成员变量第二种初始化方法：初始化块
	{
		model = "Ford";
		speed = 10.0;		
		
	}
	*/
	// 成员变量的默认值：整型（0）、double（0.0）、引用类型(空引用：null)、字符类型（空字符、‘\u0000’）、布尔型（false）
	Car(){//同名构造方法实现静态的多态
		this("Ford",15,2019,0.0);
	}
	
	Car(String model){
		//有一个参数的构造方法
		this.model = model;
		counter++;
	}
	
	Car(String model,double price,int year){
		//有三个参数的构造方法
		this.model = model;
		this.price = price;
		this.year = year;
		counter++;
	}
	
	public Car(String model,double price,int year,double speed){//构造方法：方法名与类同名 一定没有返回值，系统的默认的构造方法无参方法体为空
		//有四个参数的构造函数
		this.model = model;
		this.price = price;
		this.year = year;
		this.speed = speed;
		counter++;
	}
	
	public String getModel() {
		return model;
	}
	public void setModel(String model) {
		this.model = model;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}
	public double getSpeed() {
		return speed;
	}
	public void setSpeed(double speed) {
		this.speed = speed;
	}

	// 成员方法
	/*
	// 获取成员变量的值：getter方法 public double getPrice() { return price; }	 
	// 设置成员变量的值：setter方法 
	public void setPrice(double price)	{ 
		this.price=price; 
	}
	*/
	
	public void qidong() {
		speed = 5.0;
	}
	
	public void speedUp() {
		speed += 20;
	}
	
	public void speedUp(double speed) {
		this.speed = speed;
	}
	
	public void speedDown() {
		speed -= 20;
	}
	
	public void stop() {
		speed = 0;
	}
	
	public void print() {
		System.out.println(model+" "+price+" "+year+" "+speed);
	}
	
	public String toString() {//方法覆盖 重写来自于父类的方法
		return model+" "+price+" "+year+" "+speed;
	}
}
