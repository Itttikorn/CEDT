package pane;

import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import utils.Goto;

public class NewBookPane extends GridPane {
    public NewBookPane() {
        setPadding(new Insets(12));
        setVgap(8);

        TextField bookName = input();
        TextField bookAuthor = input();
        TextField bookRating = input();
        TextField bookImage = input();
        TextField bookDescription = input();

        ColumnConstraints columnConstraints1 = new ColumnConstraints();
        columnConstraints1.setPercentWidth(25);
        columnConstraints1.setHalignment(HPos.RIGHT);

        ColumnConstraints columnConstraints2 = new ColumnConstraints();
        columnConstraints2.setPercentWidth(75);

        Button newButton = new Button("Add");
        newButton.setMaxWidth(430);
        newButton.setPrefHeight(32);
        newButton.setTextFill(Color.WHITE);
        newButton.setBackground(new Background(new BackgroundFill(Color.DARKCYAN, null, null)));
        newButton.setOnMouseClicked(mouseEvent -> handleClick(bookName.getText(),bookAuthor.getText(),bookRating.getText(),bookImage.getText(),bookDescription.getText()));

        getColumnConstraints().add(columnConstraints1);
        getColumnConstraints().add(columnConstraints2);

        add(label("Title: "),0,0);
        add(label("Author: "), 0,1);
        add(label("Rating: "),0,2);
        add(label("Image: "),0,3);
        add(label("Description: "),0,4);

        add(bookName,1,0);
        add(bookAuthor,1,1);
        add(bookRating,1,2);
        add(bookImage,1,3);
        add(bookDescription,1,4);
        add(newButton,0,5,2,1);
    }

    private Text label(String s){
        Text newText = new Text(s);
        newText.setFont(Font.font(16));
        return newText;
    }

    private TextField input(){
        TextField newTextField = new TextField();
        newTextField.setBackground(new Background(new BackgroundFill(Color.WHITE,new CornerRadii(16),null)));
        newTextField.setBorder(new Border(new BorderStroke(Color.DARKCYAN,BorderStrokeStyle.SOLID,new CornerRadii(16),null)));
        return newTextField;
    }

    private void handleClick(String name, String author, String rating, String image, String description){
        if(name.isBlank() || author.isBlank() || rating.isBlank() || image.isBlank() || description.isBlank()) return;

        item.Book newBook = new item.Book(name,author,rating,image,description);
        pane.BookListPane.getInstance().getBooks().add(newBook);
        pane.BookListPane.getInstance().setSearchedBooks(pane.BookListPane.getInstance().getBooks());
        Goto.mainPage();
    }
}
