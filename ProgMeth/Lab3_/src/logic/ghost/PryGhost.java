package logic.ghost;

import logic.game.GameController;
import utils.Config;

public class PryGhost extends LowGhost{
	private int power;
	private int ppt;

	public PryGhost(){
		this.power = Config.PryGhostPower;
		this.ppt = 0;
	}

	public PryGhost(int power){
		this.power = power;
		this.ppt = 0;
	}

	public PryGhost(int power, int ppt){
		this.power = power;
		this.ppt = ppt;
	}

	@Override
	public String toString() {
		return "PryGhost [HP: " + super.getHp() + " , Power: " + power + " , PPT: " + ppt + "]";
	}

	public void attack(){
		GameController.getInstance().setHp(GameController.getInstance().getHp()-(power-ppt));
	}

	public int getPpt() {
		return ppt;
	}

	public void setPpt(int ppt) {
		this.ppt = ppt;
	}
}
