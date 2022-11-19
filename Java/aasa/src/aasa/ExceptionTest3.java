package aasa;

public class ExceptionTest3 {
	public static void main(String[] args) {
		try {
			throw new MyException("≥ˆŒ Ã‚");
		}catch(MyException e) {
			System.out.println(e);
		}
	}
}
