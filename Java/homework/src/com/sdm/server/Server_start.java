package com.sdm.server;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
/*
 * 20012349孙达明 服务器端
 * 2021.10.20
 * email：shun_@outlook.com
 */
public class Server_start {
	//map用来存储每个连进来的 ip和 昵称+客户端对象 封装成的map对象
	public static Map<String, User> map = new HashMap<>();
	//list为了方便批量转发
	public static List<Socket> list = new ArrayList<>();
	public static void main(String[] args) {
		try {
			ServerSocket server = new ServerSocket(1233);
			while (true) {
				//测试电脑ip：172.20.10.5
				//等待客户端进来
				Socket client = server.accept();
				//读取客户端的信息
				String ip = client.getInetAddress().getHostAddress();
				//接收客户端发来的消息
				list.add(client);
				//给所有客户端广播信息
				new Thread() {
					@Override
					public void run() {
						try {
							String ip = client.getInetAddress().getHostAddress();
							while (true) {
								
								InputStreamReader in = new InputStreamReader(client.getInputStream());
								char[] buffer = new char[1024];
								int len = -1;
								char type = '0';
								if ((len = in.read(buffer)) != -1) {
									String message = new String(buffer, 0, len);
									type = message.toCharArray()[0];
									if(type=='1') {
										map.put(ip, new User(message.substring(1), client));
										type = '0';
										message = "1"+message.substring(1)+"("+ip+")";
									}
									if(type=='2') {
										type = '0';
										message = "2"+map.get(client.getInetAddress().getHostAddress()).name+"("+ip+"):"+message.substring(1);
									}
									for (int i = 0; i < Server_start.list.size(); i++) {
										Socket v = Server_start.list.get(i);
										try {
											OutputStreamWriter out = new OutputStreamWriter(v.getOutputStream());
											out.write(message);
											System.out.println(message);
											out.flush();
										} catch (IOException e) {
											// TODO Auto-generated catch block
											e.printStackTrace();
										}
									}
								}
							}
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				}.start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}

class User {
	String name;
	Socket client;

	User(String name, Socket client) {
		this.name = name;
		this.client = client;
	}
}
//服务器端：
//
//① 创建ServerSocket对象，绑定监听端口
//
//② 通过accept()方法监听客户端请求
//
//③ 连接建立后，通过输入流读取客户端发送的请求信息
//
//④ 通过输出流向客户端发送响应信息
//
//⑤ 关闭相关资源
