package com.etc;

import java.io.FileOutputStream;
import java.io.OutputStream;

public class Testmain2 {

	public static void main(String[] args) throws Exception {
		OutputStream out = new FileOutputStream("D://abc_1.txt");
		
		//字符串，getBytes转换成是字符数组
          out.write("asjflasdfsaf".getBytes());
          
          //清空输出的缓冲区
          out.flush();
          //关闭资源
          out.close();
          
          
          
	}

}
