package monkey;

public class BaseMonkey {
    private int maxHp;
    private int hp;
    private int atk;
    private int def;

    public BaseMonkey() {
        setMaxHp(30);
        setHp(30);
        setAtk(20);
        setDef(5);
    }

    public BaseMonkey(int maxHp, int atk, int def) {
        setMaxHp(maxHp);
        setHp(maxHp);
        setAtk(atk);
        setDef(def);
    }

    public int getMaxHp() {
        return maxHp;
    }

    public void setMaxHp(int maxHp) {
        if (maxHp < 0) maxHp = 0;
        this.maxHp = maxHp;
    }

    public int getHp() {
        return hp;
    }

    public void setHp(int hp) {
        if (hp < 0) hp = 0;
        if (hp > this.maxHp) hp = this.maxHp;
        this.hp = hp;
    }

    public int getAtk() {
        return atk;
    }

    public void setAtk(int atk) {
        if (atk < 0) atk = 0;
        this.atk = atk;
    }

    public int getDef() {
        return def;
    }

    public void setDef(int def) {
        if (def < 0) def = 0;
        this.def = def;
    }

    public void attack(BaseMonkey m) {
        int damage = getAtk() - m.getDef();
        m.setHp(m.getHp() - damage);
    }

    public String getType() {
        return this.getClass().getSimpleName();
    }

    @Override
    public String toString() {
        return getType() + " hp=" + getHp() + " atk=" + getAtk() + " def=" + getDef();
    }
}
