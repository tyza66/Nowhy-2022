package bao;

public class StudentTest {
	public static void main(String[] args) {
		Student[] zu = {new Student("XiaoMing",1,1)
				,new Student("XiaoMing",2,2)
				,new Student("XiaoMing",3,3)
				,new Student("XiaoMing",4,3)
				,new Student("XiaoMing",5,4)};
		for(Student one:zu) {
			if(one.getGrade() == 3) {
				System.out.println("ÐÕÃû:"+one.getName()+",Ñ§ºÅ:"+one.getId());
			}
		}
	}
}
