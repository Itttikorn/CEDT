package logic.actor;

import logic.game.GameController;
import logic.ghost.Ghost;
import logic.ghost.HighGhost;
import utils.Config;

public class Monk extends Actor{
    public Monk(){}

    @Override
    public int getLevel() {
        return Config.MonkLevel;
    }

    @Override
    public void attack() {
        if(GameController.getInstance().getGhosts().get(0) instanceof HighGhost){
            GameController.getInstance().getGhosts().get(0).decreaseHp(getLevel());
        }
    }

    @Override
    public String toString() {
        return "Monk";
    }
}