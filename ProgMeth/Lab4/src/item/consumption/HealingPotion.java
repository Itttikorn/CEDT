package item.consumption;

import item.base.BaseConsumption;
import item.usage.Healable;
import item.usage.Upgradable;

public class HealingPotion extends BaseConsumption implements Healable, Upgradable {
    private final int MAX_LEVEL;
    private final int[] RECOVER_PT;
    private int level;

    public HealingPotion() {
        super("HealingPotion");
        setLevel(0);
        MAX_LEVEL = 3;
        RECOVER_PT = new int[]{3, 5, 7, 10};
    }

    @Override
    public int getLevel() {
        return level;
    }

    @Override
    public void setLevel(int level) {
        if (level < 0 || level > MAX_LEVEL) level = 0;
        this.level = level;
    }

    public int getMaxLevel() {
        return MAX_LEVEL;
    }

    public int getRecoverPoint() {
        return RECOVER_PT[level];
    }

    @Override
    public String toString() {
        return getName() + " (+" + getRecoverPoint() + " HP, Level: " + level + ")";
    }
}
