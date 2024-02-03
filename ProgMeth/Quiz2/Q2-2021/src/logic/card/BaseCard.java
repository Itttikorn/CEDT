package logic.card;

import logic.player.Player;

public abstract class BaseCard {
    private String name;
    private int power;
    private int health;

    public BaseCard(String name, int power, int health) {
        setName(name);
        setHealth(health);
        setPower(power);
    }

    public abstract void play(Player player);

    public abstract boolean canPlay(Player player);

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        if (power < 0) power = 0;
        this.power = power;
    }

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        if (health < 0) health = 0;
        this.health = health;
    }

    public int attack(BaseCard target) {
        if (this.power > target.health) {
            int returnValue = this.power - target.health;
            target.setHealth(0);
            return returnValue;
        } else {
            target.setHealth(target.getHealth() - this.power);
            return 0;
        }
    }
}
