package com.etc;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
//10.100.8.62
public class Testmain6 {
public static void main(String[] args) throws IOException {
	ServerSocket sever =new ServerSocket(1234);
	
	Socket client= sever.accept();
	
	System.out.println(client.getInetAddress().getHostAddress());
	
	
}
}
