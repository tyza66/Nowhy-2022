package zazss;

public class Sample2 {
	private String name;
	public Sample2(){
		name = "苹果";
	}
	
	public void sell(int price){
		class Apple{
			int innerPrice = 0;
			public Apple(int price){
				innerPrice = price;
			}
			public void price(){
				System.out.println("现在啊开始销售："+name);
				System.out.println("单价为："+innerPrice);
			}
		}
		Apple apple = new Apple(price);
		apple.price();
	}
	public static void main(String[] args){
		Sample2 sample = new Sample2();
		sample.sell(100);
	}
}