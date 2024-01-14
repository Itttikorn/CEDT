package logic.components;

import java.util.Objects;

public class Ore {
    private String name;
    private int cost;

    public Ore(String name, int cost) {
        setName(name);
        if (cost < 1) {
            setCost(1);
        } else {
            setCost(cost);
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCost() {
        return cost;
    }

    public void setCost(int cost) {
        if (cost < 1) {
            this.cost = 1;
        } else {
            this.cost = cost;
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Ore ore = (Ore) o;
        return getCost() == ore.getCost() && Objects.equals(getName(), ore.getName());
    }

}
