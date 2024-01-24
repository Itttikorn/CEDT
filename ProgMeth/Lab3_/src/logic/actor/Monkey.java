package logic.actor;

import logic.game.GameController;
import logic.ghost.Ghost;
import logic.ghost.HighGhost;
import logic.ghost.LowGhost;
import logic.item.Amulet;
import logic.item.Banana;
import logic.item.Item;
import utils.Config;

public class Monkey extends Actor{
    public Monkey(){}

    @Override
    public int getLevel() {
        return Config.MonkeyLevel;
    }

    @Override
    public void attack() {
        if(GameController.getInstance().getGhosts().get(0) instanceof LowGhost){
            GameController.getInstance().getGhosts().get(0).decreaseHp(getLevel());
            for(Item i : GameController.getInstance().getItems()){
                if(i instanceof Banana){
                    GameController.getInstance().getGhosts().get(0).decreaseHp(GameController.getInstance().getGhosts().get(0).getHp());
                    break;
                }
            }
        }
    }

    @Override
    public String toString() {
        return "Monkey";
    }
}