package logic.ghost;

import logic.game.GameController;
import utils.Config;

public class GaGhost extends LowGhost{
	private int energy;
    public GaGhost(){
        this.energy = Config.GaGhostEnergy;
    }

    public GaGhost(int energy){
        this.energy = energy;
    }

    public void attack(){
        GameController.getInstance().setHp(GameController.getInstance().getHp()-energy);
    }

    @Override
    public String toString() {
        return "GaGhost [HP: "+ super.getHp() + " , Energy: " + energy + "]";
    }
}
