package table;

import item.base.BaseItem;
import item.usage.CookState;
import item.usage.Cookable;

public class Oven extends BaseTable {

    public Oven() {
        super("Oven");
    }

    @Override
    public String interact(BaseItem item) {
        if (item instanceof Cookable) {
            if (((Cookable) item).getCookState() == CookState.RAW) {
                ((Cookable) item).setCookState(CookState.COOKED);
                return "Cooking succeed";
            } else if (((Cookable) item).getCookState() == CookState.COOKED) {
                ((Cookable) item).setCookState(CookState.BURNT);
                return "Your food has been burnt";
            } else if (((Cookable) item).getCookState() == CookState.BURNT) {
                return "Your food is already burnt, cannot be cooked anymore";
            }
        }
        return "This item cannot be cooked";
    }
}
