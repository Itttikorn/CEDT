package logic.ghost;

import utils.Config;

public abstract class Ghost {
    private int hp;

    public Ghost(int hp) {
        this.hp = hp;
    }

    public boolean isDestroyed(){
        return hp < 1;
    }

    public void decreaseHp(int amount){
        int newHp = hp;
        newHp-=amount;
        if(newHp < 0) newHp = 0;
        hp = newHp;
    }

    public abstract int getLevel();

    public abstract void attack();

    public int getHp() {
        return hp;
    }
}