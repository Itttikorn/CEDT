package monkey;

import logic.game.GameSystem;

public class MommyMonkey extends BaseMonkey {
    public MommyMonkey(int maxHp, int atk, int def) {
        super(maxHp, atk, def);
    }

    public void attack(BaseMonkey m) {
        //do nothing
    }

    public void birth() {
        GameSystem.getInstance().getMonkeyContainer().add(new BaseMonkey());
    }
}
