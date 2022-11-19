package aasa;

public class ExceptionTest1 {
	public static void main(String[] args) {
		try {
			System.out.println(2/0);
		} catch(Exception e) {
			System.out.println(e);
		}finally {
			System.out.println("’‚¿Ô «finally ");
		}
	}
}
