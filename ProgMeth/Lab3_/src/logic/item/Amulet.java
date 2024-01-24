package logic.item;

import logic.game.GameController;
import utils.Config;

public class Amulet extends Item{
	public Amulet(){};

    @Override
    public int getLevel() {
        return Config.AmuletLevel;
    }

    @Override
    public void effect() {
        if(GameController.getInstance().getHp() <= 5){
            GameController.getInstance().setHp(5);
        }
    }

    @Override
    public String toString() {
        return "Amulet";
    }
}
