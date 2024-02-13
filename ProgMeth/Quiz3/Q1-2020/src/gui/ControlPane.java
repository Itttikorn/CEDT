package gui;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.Border;
import javafx.scene.layout.BorderStroke;
import javafx.scene.layout.BorderStrokeStyle;
import javafx.scene.layout.BorderWidths;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import logic.GameLogic;

import java.awt.event.MouseEvent;

public class ControlPane extends VBox{
	
	private Text gameText;
	private Button newGameButton;
	private TicTacToePane ticTacToePane;
	
	public ControlPane(TicTacToePane ticTacToePane) {
		super();
		this.ticTacToePane = ticTacToePane;
		this.setAlignment(Pos.CENTER);
		this.setPrefWidth(300);
		this.setSpacing(20);
		initializeGameText();
		initializeNewGameButton();
		getChildren().add(gameText);
		getChildren().add(newGameButton);
	}
	
	private void initializeGameText() {
		//To be implemented
		gameText = new Text("O Turn");
		gameText.setFont(Font.font(35));
	}
	
	public void updateGameText(String text) {
		//To be implemented
		gameText.setText(text);
		
	}
	
	private void initializeNewGameButton() {
		//To be implemented
		newGameButton = new Button("New Game");
		newGameButton.setPrefWidth(100);
		newGameButton.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent actionEvent) {
				newGameButtonHandler();
			}
		});
	}
	
	private void newGameButtonHandler() {
		//To be implemented
		GameLogic.getInstance().newGame();
		gameText.setText("O Turn");
		for(TicTacToeCell t : ticTacToePane.getAllCells()){
			t.initializeCellColor();
		}
	}
}
