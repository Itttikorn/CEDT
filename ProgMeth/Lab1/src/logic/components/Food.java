package logic.components;

import java.util.Objects;

public class Food {
    private String name;
    private int price;
    private int energy;

    public Food(String name, int price, int energy) {
        setName(name);
        if (price < 1) {
            setPrice(1);
        } else {
            setPrice(price);
        }
        if (energy < 1) {
            setEnergy(1);
        } else {
            setEnergy(energy);
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        if (price < 1) {
            this.price = 1;
        } else {
            this.price = price;
        }
    }

    public int getEnergy() {
        return energy;
    }

    public void setEnergy(int energy) {
        if (energy < 1) {
            this.energy = 1;
        } else {
            this.energy = energy;
        }

    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Food food = (Food) o;
        return getPrice() == food.getPrice() && getEnergy() == food.getEnergy() && Objects.equals(getName(), food.getName());
    }

}
