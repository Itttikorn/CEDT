package logic.ghost;

import logic.game.GameController;
import utils.Config;

public class PongGhost extends HighGhost{
	private int power;

    public PongGhost(){
        this.power = Config.PongGhostPower;
    }

    public PongGhost(int power){
        this.power = power;
    }

    public int getLevel(){
        return Config.PongGhostLevel;
    }

    public void attack(){
        GameController.getInstance().setHp(GameController.getInstance().getHp()-power);
    }

    public void damage(){
        for(Ghost g : GameController.getInstance().getGhosts()){
            if(g instanceof LowGhost){
                g.decreaseHp(-power);
            }
        }
    }

    @Override
    public String toString() {
        return "PongGhost [HP: " + super.getHp() + " , Power: " + power + "]";
    }
}
