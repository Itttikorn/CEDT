package logic.components;

import exception.BadStatusException;

public class Status {
    private int hp;
    private int durability;
    private int attack;
    private int magic;

    public Status(int hp, int durability, int attack, int magic) throws BadStatusException {
        this.setHp(hp);
        this.setDurability(durability);
        this.setAttack(attack);
        this.setMagic(magic);
    }

    public int getHp() {
        return hp;
    }

    public void setHp(int hp) throws BadStatusException {
        if (hp < 0) {
            throw new BadStatusException();
        }
        this.hp = hp;
    }

    public int getDurability() {
        return durability;
    }

    public void setDurability(int durability) throws BadStatusException {
        if (durability < 0) {
            throw new BadStatusException();
        }
        this.durability = durability;
    }

    public int getAttack() {
        return attack;
    }

    public void setAttack(int attack) throws BadStatusException {
        if (attack < 0) {
            throw new BadStatusException();
        }
        this.attack = attack;
    }

    public int getMagic() {
        return magic;
    }

    public void setMagic(int magic) throws BadStatusException {
        if (magic < 0) {
            throw new BadStatusException();
        }
        this.magic = magic;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Status status = (Status) o;
        return getHp() == status.getHp() && getDurability() == status.getDurability() && getAttack() == status.getAttack() && getMagic() == status.getMagic();
    }


    public void addStatus(Status another) throws BadStatusException {
        setHp(getHp() + another.getHp());
        setDurability(getDurability() + another.getDurability());
        setAttack(getAttack() + another.getAttack());
        setMagic(getMagic() + another.getMagic());
    }
}
