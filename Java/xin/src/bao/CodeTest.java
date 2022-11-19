package bao;
import java.util.Scanner;
public class CodeTest {

	public static void main(String[] args) {
		String b = new String();
		Scanner a = new Scanner(System.in);
		System.out.print("ÊäÈëÃ÷ÎÄ£º");
		b = a.nextLine();
		System.out.println(b);
		b = jiaMi(b);
		System.out.println(b);
		b = jieMi(b);
		System.out.println(b);
	}
	
	public static String jiaMi(String az) {
		String chu = new String("");
		for(char wa:az.toCharArray()) {
			if((wa >= 'A'&&wa <= 'U')||(wa >= 'a'&&wa <= 'u')) {
				chu = chu + (char)(wa+5);
			}
			if((wa >= 'V'&&wa <= 'Z')||(wa >= 'v'&&wa <= 'z')) {
				chu = chu + (char)(wa+5-26);
			}
		}
		return chu;
	}
	
	public static String jieMi(String az) {
		String chu = new String("");
		for(char wa:az.toCharArray()) {
			if((wa >= 'F'&&wa <= 'Z')||(wa >= 'f'&&wa <= 'z')) {
				chu = chu + (char)(wa-5);
			}
			if((wa >= 'A'&&wa <= 'E')||(wa >= 'a'&&wa <= 'e')) {
				chu = chu + (char)(wa-5+26);
			}
		}
		return chu;
	}
}
