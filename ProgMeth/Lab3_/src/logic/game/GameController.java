package logic.game;

import java.util.ArrayList;

import logic.actor.Actor;
import logic.actor.Villager;
import logic.ghost.Ghost;
import logic.item.Item;
import utils.GameUtils;

public class GameController {

	private int hp;
	private int score;
	private static GameController instance;
	private ArrayList <Actor> actors;
	private ArrayList <Ghost> ghosts;
	private ArrayList <Item> items;


	public GameController() {

		this.actors = new ArrayList <Actor> ();
		this.ghosts = new ArrayList <Ghost> ();
		this.items = new ArrayList <Item> ();

		initGame();

	}

	public static GameController getInstance() {
		if(instance == null)
			instance = new GameController();
		return instance;
	}

	public void play(Actor selectedActor) {
		for(Item i : items){
			i.effect();
		}
		Ghost currentGhost = ghosts.get(0);
		selectedActor.attack();
		int destroyedGhost = 0;
		for(int i=0;i<ghosts.size();i++){
			if(ghosts.get(i).isDestroyed()){
				destroyedGhost++;
				setScore(getScore()+ghosts.get(i).getLevel());
				ghosts.remove(i);
				i--;
			}
		}
		for(int i=0;i<destroyedGhost;i++){
			ghosts.add(GameUtils.getRandomGhost(true));
		}
	}
	public void updateGameController() {
		GameIO.showGameState();
		GameIO.showCurrentGhost(ghosts);
		Actor selectedActor = GameIO.selectActor(this.actors);
		GameIO.showItemList(this.items);
		play(selectedActor);
	}

	public int getHp() {
		return hp;
	}
	public void setHp(int hp) {
		this.hp = hp;
	}
	public int getScore() {
		return score;
	}
	public ArrayList<Ghost> getGhosts() {
		return ghosts;
	}
	public ArrayList<Item> getItems() {
		return items;
	}
	public void setScore(int score) {
		this.score = score;
	}
	public void addNewActor(Actor actor) {
		this.actors.add(actor);
	}
	public void addNewItem(Item item) {
		this.items.add(item);
	}
	public void addNewGhost(Ghost ghost) {
		this.ghosts.add(ghost);
	}

	//
	public boolean isGameOver(){
		if(actors.isEmpty() || getHp() <= 0) return true;
		return false;
	}
	private void initGame(){
		setHp(10);
		setScore(0);
		actors.add(new Villager());
		for(int i=0;i<10;i++){
			ghosts.add(GameUtils.getRandomGhost(false));
		}
	}
	//===========================

}
