package com.etc;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.io.Writer;

public class TestMain3 {
	public static void main(String[] args) throws Exception {
		// 实例化一个字符流（字符代表文字，八位一个字节）
		Reader read = new FileReader("D:/a.txt");
		
		
        Writer out =new FileWriter("D:/aa.txt");

		
		char[] buffer = new char[10];
		int len = -1;
		
		while ((len = read.read(buffer)) != -1) {
		System.out.print(new String(buffer, 0, len));
		out.write(buffer,0,len);
		}
		out.flush();
		out.close();
        read.close();
		
		
		
	}
}
