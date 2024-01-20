package logic.monster;

import logic.attack.Attack;

public class Leader extends Monster {
    private int maxChargeTurns;
    private int currentChargeTurns;
    private boolean isGuard;

    public Leader(String name, int hp, int def, int sp_def, Attack attack, int chargeTurns) {
        super(name, hp, def, sp_def, attack);
        setMaxChargeTurns(chargeTurns);
        setCurrentChargeTurns(0);
    }

    public int getMaxChargeTurns() {
        return maxChargeTurns;
    }

    public void setMaxChargeTurns(int maxChargeTurns) {
        this.maxChargeTurns = maxChargeTurns;
    }

    public int getCurrentChargeTurns() {
        return currentChargeTurns;
    }

    public void setCurrentChargeTurns(int currentChargeTurns) {
        if (currentChargeTurns < 0) currentChargeTurns = 0;
        if (currentChargeTurns > maxChargeTurns) currentChargeTurns = maxChargeTurns;
        this.currentChargeTurns = currentChargeTurns;
    }

    public boolean isGuard() {
        return isGuard;
    }

    public void setGuard(boolean guard) {
        isGuard = guard;
    }

    public boolean isReady() {
        return getCurrentChargeTurns() >= getMaxChargeTurns();
    }

    public int takeDamage(Attack attack) {
        if (isGuard) return 0;
        if (attack.isLeader()) {
            int hp = getHp();
            int damage = attack.calculateDamage(this);
            hp -= damage;
            setHp(hp);
            if (hp <= 0) setDead(true);
            return damage;
        } else {
            int hp = getHp();
            int damage = attack.calculateDamage(this);
            damage = (int) Math.ceil(damage * 0.5);
            hp -= damage;
            setHp(hp);
            if (hp <= 0) setDead(true);
            return damage;
        }
    }
}
