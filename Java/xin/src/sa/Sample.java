package sa;

public class Sample {
	public int id;
	private String name;
	static String type;
	public Sample(){
		id = 9527;
		name = "苹果";
		type = "水果";
	}
	public class Inner{
		private String message = "成员内部类的创建者包含以下属性";
		public void print(){
			System.out.println(message);
			System.out.println("编号："+id);
			System.out.println("名字："+name);
			System.out.println("种类："+type);
		}
	}
}