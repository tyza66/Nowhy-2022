package com.etc;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Reader;
import java.net.Socket;

public class Testmain7Client {

	public static void main(String[] args) {
		
		try {
			Socket client = new Socket("10.100.8.1", 1234);
			
	
			OutputStreamWriter pw = new OutputStreamWriter(client.getOutputStream());
			pw.write("hello ya !°¡°¡°¡");
			pw.flush();
			Thread t1 = new MyInputStreamListenerClient(client);
			t1.start();
			
			while (true) {
				
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("·þÎñ¶Ëip»ò¶Ë¿Ú´íÎó");
		}
		
	}
}
class MyInputStreamListenerClient extends Thread {
	
	public MyInputStreamListenerClient(Socket client) {
		super();
		this.client = client;
	}
	Socket client;
	@Override
	public void run() {
		try {

			while (true) {
				
				InputStreamReader in = new InputStreamReader(client.getInputStream());
				char[] buffer = new char[1024];
				int len = -1;
				if ((len = in.read(buffer)) != -1) {
					System.out.println(new String(buffer, 0, len));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

