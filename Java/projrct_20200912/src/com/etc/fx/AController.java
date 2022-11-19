package com.etc.fx;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Alert.AlertType;

public class AController {
	@FXML
	TextField txt1;
	@FXML
	Button btn1;
	
	public void clickbtn1(){
		Alert alert = new Alert(AlertType.INFORMATION);
		String str = txt1.getText();
		alert.setContentText(str);
		txt1.setText("");
		alert.show();
	}
}
