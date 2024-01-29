package item.consumption;

import item.base.BaseConsumption;
import item.usage.CookState;
import item.usage.Cookable;
import item.usage.Healable;

import java.util.HashMap;

public class Pork extends BaseConsumption implements Cookable, Healable {
    private final HashMap<CookState, Integer> RECOVER_PT;
    private CookState cookState;

    public Pork() {
        super("Pork");
        cookState = CookState.RAW;
        RECOVER_PT = new HashMap<>();
        RECOVER_PT.put(CookState.RAW, 1);
        RECOVER_PT.put(CookState.COOKED, 2);
        RECOVER_PT.put(CookState.BURNT, 0);
    }

    public int getRecoverPoint() {
        return RECOVER_PT.get(cookState);
    }

    @Override
    public String toString() {
        return cookState.toString().charAt(0) + cookState.toString().substring(1).toLowerCase() + " " + getName() + " (+" + getRecoverPoint() + " HP)";
    }

    public CookState getCookState() {
        return cookState;
    }

    public void setCookState(CookState cookState) {
        this.cookState = cookState;
    }
}
