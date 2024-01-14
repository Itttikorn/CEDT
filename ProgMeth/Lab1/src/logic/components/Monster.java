package logic.components;

public class Monster {
    private String name;
    private Status status;
    private Food food;
    private Potion potion;

    public Monster(String name, Status status) {
        setName(name);
        if (status.getHp() < 1) {
            try {
                status.setHp(1);
            } catch (Exception e) {
                //do nothing
            }
        }
        setStatus(status);
        setFood(null);
        setPotion(null);
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

    public Food getFood() {
        return food;
    }

    public void setFood(Food food) {
        this.food = food;
    }

    public Potion getPotion() {
        return potion;
    }

    public void setPotion(Potion potion) {
        this.potion = potion;
    }

    public void attack(Player player) {
        int damage = this.getStatus().getAttack();
        int playerHp = player.getStatus().getHp();
        damage -= player.getStatus().getDurability();
        if (damage < 0) {
            damage = 0;
        }
        if (playerHp - damage < 0) {
            damage = playerHp;
        }
        try {
            player.getStatus().setHp(playerHp - damage);
        } catch (Exception e) {
            //do nothing
        }
    }

    public void magicAttack(Player player) {
        int damage = this.getStatus().getMagic();
        int playerHp = player.getStatus().getHp();
        if (damage < 0) {
            damage = 0;
        }
        if (playerHp - damage < 0) {
            damage = playerHp;
        }
        try {
            player.getStatus().setHp(playerHp - damage);
        } catch (Exception e) {
            //do nothing
        }
    }

}
