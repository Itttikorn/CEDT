package logic.rocks;

import logic.zombies.Zombie;

public class NormalRock {
    protected int damage;

    public NormalRock(int damage) {
        setDamage(damage);
    }

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        if (damage < 0) damage = 0;
        this.damage = damage;
    }

    public int dealDamage(Zombie zombie) {
        int damageDealt = 0;
        if (zombie.getDefense() >= getDamage()) {
            return damageDealt;
        }
        damageDealt = getDamage() - zombie.getDefense();
        zombie.setHealth(zombie.getHealth() - damageDealt);
        return damageDealt;
    }

    public String toString() {
        return "Normal Rock (" + getDamage() + ")";
    }
}
