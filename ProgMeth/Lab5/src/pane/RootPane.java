package pane;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import utils.Goto;

public class RootPane extends VBox {
    private static RootPane instance;

    private RootPane() {
        BackgroundFill newBackgroundFill = new BackgroundFill(Color.WHITE,null,null);
        Background newBackground = new Background(newBackgroundFill);
        setBackground(newBackground);
        setAlignment(Pos.TOP_CENTER);
        setSpacing(16);
        Insets newInsets = new Insets(32, 0, 32, 0);
        setPadding(newInsets);
        Text newText = new Text("Let's Read");
        newText.setFill(Color.DARKCYAN);
        newText.setFont(Font.font("Verdana", FontWeight.BOLD,32));
        getChildren().add(newText);
        ///////////////////////
        Goto.setRootPane(this);
        Goto.mainPage();
    }

    public static RootPane getRootPane() {
        if (instance == null)
            instance = new RootPane();
        return instance;
    }
}
