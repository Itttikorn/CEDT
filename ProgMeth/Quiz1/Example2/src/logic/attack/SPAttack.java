package logic.attack;

import logic.monster.Monster;

public class SPAttack extends Attack {
    public SPAttack(int power, String name, boolean isLeader) {
        super(power, name, isLeader);
    }

    public int calculateDamage(Monster target) {
        int damage = super.power - target.getSpecialDefense();
        if (damage < 0) damage = 0;
        return damage;
    }
}
