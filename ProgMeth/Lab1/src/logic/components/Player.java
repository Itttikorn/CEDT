package logic.components;

import java.util.ArrayList;

public class Player {
    private String name;
    private Status status;
    private int energy;
    private int money;
    private ArrayList<Food> foods;
    private ArrayList<Potion> potions;
    private ArrayList<Ore> ores;

    public Player(String name, Status status) {
        setName(name);
        if (status.getHp() < 1) {
            try {
                status.setHp(1);
            } catch (Exception e) {
                //do nothing
            }
        }
        setStatus(status);
        setEnergy(10);
        setMoney(100);
        setFoods(new ArrayList<Food>());
        setPotions(new ArrayList<Potion>());
        setOres(new ArrayList<Ore>());
        this.name = name;
    }

    public Player(String name, Status status, int energy, int money) {
        setName(name);
        if (status.getHp() < 1) {
            try {
                status.setHp(1);
            } catch (Exception e) {
                //do nothing
            }
        }
        setStatus(status);
        setEnergy(energy);
        setMoney(money);
        setFoods(new ArrayList<Food>());
        setPotions(new ArrayList<Potion>());
        setOres(new ArrayList<Ore>());
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    public int getEnergy() {
        return energy;
    }

    public void setEnergy(int energy) {
        if (energy < 0) {
            this.energy = 0;
        } else {
            this.energy = energy;
        }
    }

    public int getMoney() {
        return money;
    }

    public void setMoney(int money) {
        if (money < 0) {
            this.money = 0;
        } else {
            this.money = money;
        }
    }

    public ArrayList<Food> getFoods() {
        return foods;
    }

    public void setFoods(ArrayList<Food> foods) {
        this.foods = foods;
    }

    public ArrayList<Potion> getPotions() {
        return potions;
    }

    public void setPotions(ArrayList<Potion> potions) {
        this.potions = potions;
    }

    public ArrayList<Ore> getOres() {
        return ores;
    }

    public void setOres(ArrayList<Ore> ores) {
        this.ores = ores;
    }

    public boolean buyOre(Ore ore) {
        if (this.money >= ore.getCost()) {
            this.money -= ore.getCost();
            this.ores.add(ore);
            return true;
        } else {
            return false;
        }
    }

    public void drinkPotion(int index) {
        try {
            this.status.addStatus(this.potions.get(index).getIncreasingStatus());
            this.potions.remove(index);
        } catch (Exception e) {
            //do nothing
        }
    }

    public void eatFood(int index) {
        try {
            this.energy += this.foods.get(index).getEnergy();
            this.foods.remove(index);
        } catch (Exception e) {
            //do nothing
        }
    }

    public void sellPotion(int index) {
        try {
            this.money += this.potions.get(index).getPrice();
            this.potions.remove(index);
        } catch (Exception e) {
            //do nothing
        }
    }

    public void sellFood(int index) {
        try {
            this.money += this.foods.get(index).getPrice();
            this.foods.remove(index);
        } catch (Exception e) {
            //do nothing
        }
    }

    public void attack(Monster monster) {
        int damage = this.getStatus().getAttack();
        int monsterHp = monster.getStatus().getHp();
        damage -= monster.getStatus().getDurability();
        if (damage < 0) {
            damage = 0;
        }
        if (monsterHp - damage < 0) {
            damage = monsterHp;
        }
        try {
            monster.getStatus().setHp(monsterHp - damage);
        } catch (Exception e) {
            //do nothing
        }
    }

    public void magicAttack(Monster monster) {
        int damage = this.getStatus().getMagic();
        int monsterHp = monster.getStatus().getHp();
        if (damage < 0) {
            damage = 0;
        }
        if (monsterHp - damage < 0) {
            damage = monsterHp;
        }
        try {
            monster.getStatus().setHp(monsterHp - damage);
        } catch (Exception e) {
            //do nothing
        }
    }

}
