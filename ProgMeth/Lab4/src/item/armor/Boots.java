package item.armor;

import item.base.BaseArmor;

public class Boots extends BaseArmor {
    private final int DEF;

    public Boots() {
        super("Boots", 5);
        DEF = 1;
    }

    @Override
    public int getDef() {
        return DEF;
    }
}
