package logic.ghost;

import logic.game.GameController;
import utils.Config;

public class MaBongGhost extends LowGhost{
	private int power;
    private int speed;

    public MaBongGhost(){
        this.power = Config.MaBongGhostPower;
        this.speed = Config.MaBongGhostSpeed;
    }

    public MaBongGhost(int power){
        this.power = power;
        this.speed = Config.MaBongGhostSpeed;
    }

    public MaBongGhost(int power, int speed){
        this.power = power;
        this.speed = speed;
    }

    @Override
    public String toString() {
        return "MaBongGhost [HP: " + super.getHp() + " , Power: " + power + " , Speed: " + speed + "]";
    }

    public void attack(){
        GameController.getInstance().setHp(GameController.getInstance().getHp()-(power*speed));
    }
}
