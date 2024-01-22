package logic.rocks;

import logic.zombies.Zombie;

public class PoisonRock extends NormalRock {
    private int damageOverTime;

    public PoisonRock(int damage, int damageOverTime) {
        super(damage);
        setDamageOverTime(damageOverTime);
    }

    public int getDamageOverTime() {
        return damageOverTime;
    }

    public void setDamageOverTime(int damageOverTime) {
        if (damageOverTime < 0) damageOverTime = 0;
        this.damageOverTime = damageOverTime;
    }

    @Override
    public int dealDamage(Zombie zombie) {
        zombie.setDecay(zombie.getDecay() + getDamageOverTime());
        return super.dealDamage(zombie);
    }

    public String toString() {
        return "Poison Rock (" + getDamage() + ", DoT = "
                + getDamageOverTime() + ")";
    }
}
