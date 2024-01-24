package logic.actor;

import logic.game.GameController;
import logic.ghost.Ghost;
import logic.ghost.HighGhost;
import logic.ghost.LowGhost;
import logic.item.Amulet;
import logic.item.Banana;
import logic.item.Item;
import utils.Config;

public class GhostDoctor extends Actor{
    public GhostDoctor(){}

    @Override
    public int getLevel() {
        return Config.GhostDoctorLevel;
    }

    @Override
    public void attack() {
        if(GameController.getInstance().getGhosts().get(0) instanceof LowGhost){
            GameController.getInstance().getGhosts().get(0).decreaseHp(GameController.getInstance().getGhosts().get(0).getHp());
        }
    }

    @Override
    public String toString() {
        return "GhostDoctor";
    }
}