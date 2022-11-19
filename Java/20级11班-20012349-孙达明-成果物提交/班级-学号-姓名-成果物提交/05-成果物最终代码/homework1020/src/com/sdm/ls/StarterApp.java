package com.sdm.ls;

import java.io.IOException;
import java.io.InputStreamReader;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/*
 * 20012349孙达明 客户端
 * 2021.10.20
 * email：shun_@outlook.com
 */
public class StarterApp extends Application {

	public static void main(String[] args) {
		// 启动窗口程序
		launch();
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		// 加载fxml文件
		Parent root = FXMLLoader.load(this.getClass().getResource("/main2.fxml"));
		Scene scene = new Scene(root, 600, 400);
		primaryStage.setScene(scene);
		primaryStage.setTitle("局域网聊天室");
		primaryStage.show();
	}
}
//客户端：
//
//① 创建Socket对象，指明需要连接的服务器的地址和端口号
//
//② 连接建立后，通过输出流想服务器端发送请求信息
//
//③ 通过输入流获取服务器响应的信息
//
//④ 关闭响应资源 

//Socket通信的步骤
//
//① 创建ServerSocket和Socket
//
//② 打开连接到Socket的输入/输出流
//
//③ 按照协议对Socket进行读/写操作
//
//④ 关闭输入输出流、关闭Socket
