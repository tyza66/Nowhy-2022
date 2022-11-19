package dasdas;

import java.util.Iterator;
import java.util.TreeSet;

public class Employee implements Comparable{
	private  int id;
	public String name;
	
	private Employee(int id,String name) {
		this.id = id;
		this.name = name;
	}
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	@Override
	public int compareTo(Object o) {
		Employee az = (Employee)o;
		return id-az.getId();
	}
	
	public static void main(String[] args) {
		Employee a1 = new Employee(2000,"0");
		Employee a2 = new Employee(2001,"1");
		Employee a3 = new Employee(2002,"2");
		Employee a4 = new Employee(2003,"3");
		Employee a5 = new Employee(2004,"4");
		
		TreeSet<Employee> y = new TreeSet<Employee>();
		y.add(a1);
		y.add(a3);y.add(a2);
		y.add(a4);
		y.add(a5);
		for(Iterator<Employee> it = y.iterator();it.hasNext();) {
			Employee s = it.next();
			System.out.println(s.getId()+"---"+s.name);
		}
	}
}
