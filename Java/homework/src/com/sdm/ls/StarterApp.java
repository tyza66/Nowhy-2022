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
		primaryStage.setTitle("hello javaFX");
		primaryStage.show();
	}
}
