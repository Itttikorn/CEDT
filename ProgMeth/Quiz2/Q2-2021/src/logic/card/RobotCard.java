package logic.card;

import logic.player.Player;

public class RobotCard extends BaseCard{
    private int energyCost;

    public RobotCard(String name, int power, int health, int energyCost){
        super(name, power, health);
        setEnergyCost(energyCost);
    }

    public int getEnergyCost() {
        return energyCost;
    }

    public void setEnergyCost(int energyCost) {
        if(energyCost < 0) energyCost = 0;
        this.energyCost = energyCost;
    }

    @Override
    public void play(Player player) {
        if(player.getEnergy() < energyCost){
            player.setEnergy(0);
        }else{
            player.setEnergy(player.getEnergy()-energyCost);
        }
    }

    @Override
    public boolean canPlay(Player player) {
        if(player.getEnergy() < energyCost) return false;
        return true;
    }
}
