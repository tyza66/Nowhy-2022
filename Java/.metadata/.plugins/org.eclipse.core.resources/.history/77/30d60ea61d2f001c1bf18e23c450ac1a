package com.etc;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;

public class TestMain6Server {
	// 客户端映射： ip对应socket
	public static Map<String, Socket> map = new HashMap<String, Socket>();
	
	public static void main(String[] args) {
		// 我的IP :  10.100.8.1:1234
		
		try {
			ServerSocket server = new ServerSocket(1234);
			
			while (true) {
				// 线程阻塞 等待客户端访问时继续走
				// 服务的获取客户端对象
				Socket client = server.accept();
				String ip = client.getInetAddress().getHostAddress();
				map.put(ip, client);
				
				System.out.println(ip);
//				PrintWriter pw = new PrintWriter(client.getOutputStream());
//				
//				pw.append("<html><body><h1>hello world</h1></body></html>");
//				pw.flush();

				// 开启了输入流监控 
				new Thread() {

					@Override
					public void run() {
						try {
							InputStreamReader inreader = new InputStreamReader(client.getInputStream());
							char[] buffer = new char[1024];
							int len = -1;
							while (true) {
								if ((len = inreader.read(buffer)) != -1) {
									// 群发：
									String message = ip + "say:" + new String(buffer, 0, len);
									map.forEach((k, v) -> {
										try {
											OutputStreamWriter pw = new OutputStreamWriter(client.getOutputStream());
											pw.write(message);
											pw.flush();
										} catch (IOException e) {
											// TODO Auto-generated catch block
											e.printStackTrace();
										}
										;
									});
									System.out.println(message);
								}
							}
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				}.start();

			}

			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("端口被占用");
		}
	}
}
