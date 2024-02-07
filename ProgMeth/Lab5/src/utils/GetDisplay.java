package utils;

import javafx.scene.image.ImageView;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;

public class GetDisplay {
    public static Text Description(item.Book book, int fontSize, int wrappingWidth){
        Text newText = new Text(book.getDescription());
        newText.setFont(Font.font(fontSize));
        newText.setWrappingWidth(wrappingWidth);
        return newText;
    }

    public static ImageView image(item.Book book, int fitHeight ){
        ImageView newImageView = new ImageView(book.getImage());
        newImageView.setPreserveRatio(true);
        newImageView.setFitHeight(fitHeight);
        return newImageView;
    }

    public static Text name(item.Book book, int fontSize, int wrappingWidth, TextAlignment textAlignment){
        Text newText = new Text(book.getName());
        newText.setFont(Font.font(fontSize));
        newText.setWrappingWidth(wrappingWidth);
        newText.setTextAlignment(textAlignment);
        return newText;
    }

    public static Text author(item.Book book, int fontSize, int wrappingWidth, TextAlignment textAlignment){
        Text newText = new Text(book.getAuthor());
        newText.setFill(Color.GRAY);
        newText.setFont(Font.font(fontSize));
        newText.setTextAlignment(textAlignment);
        return newText;
    }

    public static Text stars(item.Book book, int fontSize){
        Text newText = new Text();
        String starsText = "\u2605".repeat(book.getStars()) + "\u2606".repeat(5- book.getStars());
        newText.setFill(Color.DARKRED);
        newText.setFont(Font.font(fontSize));
        newText.setText(starsText);
        return newText;
    }
}
