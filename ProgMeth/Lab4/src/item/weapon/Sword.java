package item.weapon;

import item.base.BaseWeapon;
import item.usage.Upgradable;

public class Sword extends BaseWeapon implements Upgradable {
    private final int MAX_LEVEL;
    private final int[] ATT;
    private int level;

    public Sword() {
        super("Sword", 15, 1);
        setLevel(0);
        MAX_LEVEL = 3;
        ATT = new int[]{3, 5, 8, 12};
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        if (level < 0 || level > MAX_LEVEL) level = 0;
        this.level = level;
    }

    public int getMaxLevel() {
        return MAX_LEVEL;
    }

    public int getAtt() {
        return ATT[getLevel()];
    }

    @Override
    public String toString() {
        return getName() + " (Att: " + getAtt() + ", Range: " + getRange() + ", Level: " + level + ", " + getDurability() + " uses left)";
    }
}
