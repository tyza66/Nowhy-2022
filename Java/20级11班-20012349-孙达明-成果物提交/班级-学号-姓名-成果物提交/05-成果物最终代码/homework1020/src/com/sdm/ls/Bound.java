package com.sdm.ls;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

/*
 * 20012349孙达明 窗口的事件与控件绑定
 * 2021.10.20
 * email：shun_@outlook.com
 */
public class Bound {
	// 绑定控件id
	@FXML
	TextField t1;
	@FXML
	TextField t2;
	@FXML
	TextField t3;
	@FXML
	TextField t4;
	@FXML
	TextArea i1;
	@FXML
	TextArea i2;
	@FXML
	Button b4;
	@FXML
	Button b5;
	// 连接状态对象
	public static Socket client = null;
	//待用输入流
	InputStreamReader in = null;
	//当点击连接按钮时触发事件
	public void click_b4() throws IOException {
		//当没有进行第一次链接时，点击连接按钮执行连接操作，连接成功后显示弹窗已连接，有效避免登陆多次使服务器列表重复出现同一客户端
		if(client==null) {
		String name = t1.getText();
		String ip = t2.getText();
		int port = Integer.parseInt(t3.getText());
		client = new Socket(ip, port);
		OutputStreamWriter pw = new OutputStreamWriter(client.getOutputStream());
		pw.write("1"+name);
		pw.flush();
		new Thread() {
			@Override
			public void run() {
				while (true) {
					System.out.print("");
					if(Bound.client!=null)
					try {
						in = new InputStreamReader(Bound.client.getInputStream());
						char[] buffer = new char[1024];
						int len = -1;
						String message = "";
						if ((len = in.read(buffer)) != -1) {
							message = message + new String(buffer, 0, len);
						}
						System.out.println(message);
						if(message.toCharArray()[0]=='1') {
							i1.appendText(message.substring(1)+"上线了"+"\n");
						}
						if(message.toCharArray()[0]=='2') {
							i2.appendText(message.substring(1)+"\n");
						}
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}

				}
			}
		}.start();
		}else {
			Alert alter = new Alert(AlertType.INFORMATION);
			alter.setContentText("已上线");
			alter.show();
		}
		
	}

	// 点击发送消息时候事件
	public void click_b5() {
		if(in != null) {
			OutputStreamWriter pw;
			try {
				pw = new OutputStreamWriter(Bound.client.getOutputStream());
				pw.write("2"+t4.getText());
				pw.flush();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		else {
			Alert alter = new Alert(AlertType.INFORMATION);
			alter.setContentText("请先上线");
			alter.show();
		}
	}
}
//网络编程最主要的工作就是在发送端把信息通过规定好的协议进行组装包，在接收端按照规定好的协议把包进行解析，从而提取出对应的信息，达到通信的目的。中间最主要的就是数据包的组装，数据包的过滤，数据包的捕获，数据包的分析，当然最后再做一些处理，代码、开发工具、数据库、服务器架设和网页设计这5部分你都要接触。
//静态代码
//静态代码是服务器不解析直接发送给客户端的部分，用做布局效果，一般不用于数据库操作
//静态代码分html，javascript，css等，其中 [1]  html语言是基础，要学网络编程就先学html语言.javascript用于实现某些特效，css是样式语言.这3个语言组合起来，可以设计出美妙的网页效果
//动态代码
//动态代码是服务器需要解析的部分，用作数据库连接操作等.有php，jsp，asp这几种语言你只用先学一种就可.如果是想快速入门，建议先学asp，如果想学了找工作等，建议学php或jsp，
//开发工具有很多种，我推荐一种，网络3剑客，其中dw是开发代码的，fw是做图的.flash是做动画的.
//数据库要结合你学的动态语言来选择，asp系列的，你可以使用access，大型点使用mySQL.
//php和mySQL是很好的搭档.
//服务器架设也是结合你学的动态语言的，windows下安装iis很方便，iis可以运行asp，安装.net框架后能运行，这两者架设相对简单，也是我推荐你入门学asp的原因.php一般安装apache服务器，jsp一般安装tomcat服务器.只有架设好服务器，才能浏览动态语言编写的程序.
//虽然是编程，但是总会涉及到网页设计部分，还是要去学学怎么简单的作图和动画。
