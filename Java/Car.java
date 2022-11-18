package Text1;

public class Car { // 公共类
	// 成员变量:private
	/*
	 * public String model;//品牌 项目级别 公共 double price;//价格 包可以访问的 private int
	 * year;//出厂年 本类 double speed;//速度 保护成员 在car的子类里有用
	 */
	private String model;// 品牌 项目级别 公共
	private double price=58.8;// 价格 包可以访问的
	private int year=2020;// 出厂年 本类
	private double speed;// 速度 保护成员 在car的子类里有用
	// 成员变量默认值：整型（0）、double（0.0）、引用类型（空引用：null）、字符类型（空字符：\u0000）、布尔型（false）
	
	//第二种初始化方法 初始化块
	{
		model="Forf";
		speed=10.0;
	}
	// 成员方法
	// 获取成员变量的值的方法:getter
	public double getPrice() {
		return price;
	}
	
	// 获取成员变量的值的方法:getter
		public void setPrice() {
			price = 12.8;
		}

		public String getModel() {
			return model;
		}

		public void setModel(String model) {
			this.model = model;
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

		public void setPrice(double price) {
			this.price = price;
		}
	
}
