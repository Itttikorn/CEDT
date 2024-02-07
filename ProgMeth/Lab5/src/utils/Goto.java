package utils;

import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.ScrollPane;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import jdk.jshell.execution.Util;
import pane.BookListPane;
import pane.NewBookPane;
import pane.RootPane;
import pane.SearchPane;

public class Goto {
    private static RootPane rootPane;

    public static void setRootPane(RootPane rootPane) {
        Goto.rootPane = rootPane;
    }

    public static void clear() {
        if (rootPane.getChildren().size() <= 1) return;
        for (int i = rootPane.getChildren().size() - 1; i > 0; i--) {
            rootPane.getChildren().remove(i);
        }
    }

    public static void mainPage() {
        clear();

        ScrollPane newScrollPane = new ScrollPane(BookListPane.getInstance());
        newScrollPane.setHbarPolicy(ScrollPane.ScrollBarPolicy.NEVER);
        newScrollPane.setVbarPolicy(ScrollPane.ScrollBarPolicy.NEVER);

        rootPane.getChildren().add(new SearchPane());
        rootPane.getChildren().add(newScrollPane);
    }

    public static Button backToMainButton() {
        Button newButton = new Button("Back");
        BorderStroke newBorderStroke = new BorderStroke(Color.DARKCYAN, BorderStrokeStyle.SOLID, null, new BorderWidths(2));
        Border newBorder = new Border(newBorderStroke);
        newButton.setBorder(newBorder);
        BackgroundFill newBackgroundFill = new BackgroundFill(Color.WHITE,null,null);
        Background newBackground = new Background(newBackgroundFill);
        newButton.setBackground(newBackground);
        newButton.setTextFill(Color.DARKCYAN);
        newButton.setPrefWidth(300);

        newButton.setOnMouseClicked(mouseEvent -> mainPage());

        return newButton;
    }

    public static void bookPage(item.Book book){
        clear();

        Text bookName = GetDisplay.name(book,28,336,TextAlignment.CENTER);
        Text bookAuthor = GetDisplay.author(book,24,336,TextAlignment.CENTER);
        bookAuthor.setText("By " + book.getAuthor());
        javafx.scene.image.ImageView bookImage = GetDisplay.image(book,320);
        Text bookStar = GetDisplay.stars(book,24);
        Text bookDescription = GetDisplay.Description(book, 16,336);
        RootPane.getRootPane().getChildren().add(backToMainButton());
        RootPane.getRootPane().getChildren().add(bookName);
        RootPane.getRootPane().getChildren().add(bookAuthor);
        RootPane.getRootPane().getChildren().add(bookImage);
        RootPane.getRootPane().getChildren().add(bookStar);
        RootPane.getRootPane().getChildren().add(bookDescription);
    }

    public static void addNewBookPage(){
        clear();
        RootPane.getRootPane().getChildren().add(backToMainButton());
        RootPane.getRootPane().getChildren().add(new NewBookPane());
    }
}
