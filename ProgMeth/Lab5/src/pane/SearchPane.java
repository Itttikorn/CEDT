package pane;

import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;

import java.awt.*;
import java.util.ArrayList;

public class SearchPane extends HBox {
    public SearchPane(){
        setAlignment(Pos.CENTER);

        TextField newTextField = new TextField();
        newTextField.setPromptText("Find the book");
        newTextField.setPrefWidth(250);

        javafx.scene.control.Button newButton = new Button("Search");
        Background buttonBackground = new Background(new BackgroundFill(Color.DARKCYAN,null,null));
        newButton.setBackground(buttonBackground);
        newButton.setTextFill(Color.WHITE);
        newButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent mouseEvent) {
                if(newTextField.getText().isBlank()){
                    pane.BookListPane.getInstance().setSearchedBooks(pane.BookListPane.getInstance().getBooks());
                }else{
                    ArrayList<item.Book> searchedBookList = new ArrayList<>(pane.BookListPane.getInstance().getBooks());
                    searchedBookList.removeIf(book -> !book.getName().contains(newTextField.getText()));
                    pane.BookListPane.getInstance().setSearchedBooks(searchedBookList);
                }
            }
        });
        getChildren().add(newTextField);
        getChildren().add(newButton);
    }
}
