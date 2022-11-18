package bao;

public class ResultTest {
	public static void main(String[] args) {
		int i = 0,j = 0,sum = 0,max = 0,hang = 0,hang2 = 0;
		int a1 = 0,a2 = 0,a3 = 0,a4 = 0;
		int b1 = 0,b2 = 0,b3 = 0,b4 = 0;
		int[][] chengji = {
				{80,75,78,93},
				{67,87,98,65},
				{86,72,60,76},
				{76,80,76,63},
				{82,70,90,67}};
			for(i=0;i<5;i++) {
				if(chengji[i][0] > a1) {a1 = chengji[i][0];b1 = i+1;}
			}
			for(i=0;i<5;i++) {
				if(chengji[i][1] > a2) {a2 = chengji[i][1];b2 = i+1;}
			}
			for(i=0;i<5;i++) {
				if(chengji[i][2] > a3) {a3 = chengji[i][2];b3 = i+1;}
			}
			for(i=0;i<5;i++) {
				if(chengji[i][3] > a4) {a4 = chengji[i][3];b4 = i+1;}
			}
		System.out.print("每科最高分和所在行分别在：["+a1+","+b1+"],["+a2+","+b2+"],["+a3+","+b3+"],["+a4+","+b4+"]");
		for(int[] one:chengji) {
			for(int hia:one) {
				sum += hia; 
			}
			if(sum > max) {max = sum; hang2 = hang;}
			sum = 0;hang++;
		}
		System.out.print("最高分在第"+(hang2+1)+"行,总成绩是"+max);

	}
}
