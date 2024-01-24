package logic.item;

import logic.game.GameController;
import logic.ghost.Ghost;
import logic.ghost.HighGhost;
import logic.ghost.LowGhost;
import utils.Config;

public class Leklai extends Item{
	public Leklai(){}

    @Override
    public int getLevel() {
        return Config.LeklaiLevel;
    }

    @Override
    public void effect() {
        for(Ghost g : GameController.getInstance().getGhosts()){
            if(g.getLevel() <= getLevel()){
                if(g instanceof LowGhost){
                    g.decreaseHp(5);
                } else if (g instanceof HighGhost) {
                    g.decreaseHp(4);
                }
            }
        }
    }

    @Override
    public String toString() {
        return "Leklai";
    }
}
