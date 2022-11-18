package tPC;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Start extends Application {

    public static void main(String[] args) {
        launch(args);
    }

	@Override
	public void start(Stage primaryStage) throws Exception {
		
		Parent root = FXMLLoader.load(this.getClass().getResource("/MyChatRoom.fxml"));
		
		Scene scene = new Scene(root, 400, 400);
		primaryStage.setScene(scene);
		primaryStage.setTitle("hello javaFX");
		primaryStage.show();
	}
}
