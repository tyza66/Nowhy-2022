package da;
import java.util.Scanner;
public class xiao {

	private static Scanner in;

	public static void main(String[] args) {
		int l=0,m=0;
		System.out.println("请输入十个数：");
		in = new Scanner(System.in);
		int[] b=new int[10];
		for(int a=0;a<b.length;a++) {
			 b[a]=in.nextInt();}
		l=m=b[0];
		for(int c=0;c<=9;c++) {
			if(b[c]>l) l=b[c];
			if(b[c]<m) m=b[c];
		}
		System.out.println("其中最大值为："+l);
		System.out.println("其中最小值为"+m);
	}}