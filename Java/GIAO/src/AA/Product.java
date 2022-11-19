package AA;

import java.util.Objects;

public class Product implements Cloneable{
	private int id;
	private String name;
	private String brand;
	private double price;
	public Product() {}
	public Product(int id,String name,String brand,double price) {
		this.id = id;
		this.name = name;
		this.brand = brand;
		this.price = price;
	}
	public boolean equals(Object obj) {
		return this.hashCode()==obj.hashCode();
	}
	public int hashCode() {
		return Objects.hash(id,name,brand,price);
	}
	public String toString() {
		return ""+Objects.hash(id,name,brand,price);
	}
	@Override
	public Object clone()throws CloneNotSupportedException{
		return super.clone();
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getBrand() {
		return brand;
	}
	public void setBrand(String brand) {
		this.brand = brand;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	} 
	
}
