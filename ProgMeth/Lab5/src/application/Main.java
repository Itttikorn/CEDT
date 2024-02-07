package application;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    public static void main(String[] args) {
        launch();
    }

    @Override
    public void start(Stage stage) {
        Scene newScene = new Scene(pane.RootPane.getRootPane(),430,932);
        stage.setScene(newScene);
        stage.setTitle("Let's Read");
        stage.setResizable(false);
        stage.show();
    }
}