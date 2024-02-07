package pane;

import javafx.geometry.Insets;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import utils.GetDisplay;
import utils.Goto;

public class BookPane extends GridPane {
    public BookPane(item.Book book){
        setPrefWidth(428);
        setHgap(8);
        setPadding(new Insets(4));

        ImageView bookImage = GetDisplay.image(book,160);
        add(bookImage,0,0,1,4);

        Text bookName = GetDisplay.name(book,18,250, TextAlignment.LEFT);
        add(bookName, 1,0);

        Text bookAuthor = GetDisplay.author(book,16,250,TextAlignment.LEFT);
        add(bookAuthor,1,1);

        Text bookStars = GetDisplay.stars(book,16);
        add(bookStars,1,3);

        setOnMouseClicked(mouseEvent -> Goto.bookPage(book));
    }
}
