package logic.ghost;

import logic.game.GameController;
import utils.Config;

public class PooYaGhost extends HighGhost{
	private int power;
    public PooYaGhost(int power){
        this.power = power;
    }
    public int getLevel(){
        return Config.PooYaGhostLevel;
    }

    @Override
    public String toString() {
        return "PooYaGhost [HP: " + super.getHp() + " , Power: " + power + "]";
    }

    public void attack(){
        GameController.getInstance().setHp(GameController.getInstance().getHp()-power);
        GameController.getInstance().setScore(GameController.getInstance().getScore()-power);
    }

    public void damage() {
        for (Ghost g : GameController.getInstance().getGhosts()) {
            g.decreaseHp(-power);
        }
    }
}
