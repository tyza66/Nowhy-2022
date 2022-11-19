package aasa;

public class MyException extends Exception{
	String name;
	MyException(String name){
		this.name = name;
	}
	public String toString() {
		return name;
	}
}
