package com.etc;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;

import javax.swing.InputMap;

public class Testmain7 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Socket client = new Socket("10.100.8.1", 1234);

		InputStreamReader inneader = new InputStreamReader(client.getInputStream());

		char[] buffer = new char[1024];

		int len = -1;
		
		while ((len = inneader.read(buffer)) != -1) {
			System.out.println(len);
			System.out.println(new String(buffer, 0, len));
		}
		System.out.println();
	}

}
