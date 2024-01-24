package logic.actor;

import logic.game.GameController;
import logic.ghost.Ghost;
import logic.ghost.HighGhost;
import logic.ghost.LowGhost;
import logic.item.Amulet;
import logic.item.Item;
import utils.Config;

public class Villager extends Actor{
    public Villager(){};

    @Override
    public int getLevel() {
        return Config.VillagerLevel;
    }

    @Override
    public void attack() {
        if(GameController.getInstance().getGhosts().get(0) instanceof  LowGhost){
            GameController.getInstance().getGhosts().get(0).decreaseHp(getLevel());
            for(Item i : GameController.getInstance().getItems()){
                if(i instanceof Amulet){
                    GameController.getInstance().getGhosts().get(0).decreaseHp(getLevel()+1);
                    break;
                }
            }
        }
    }

    @Override
    public String toString() {
        return "Villager";
    }
}