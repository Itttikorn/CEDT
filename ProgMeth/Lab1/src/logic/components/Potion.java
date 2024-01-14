package logic.components;

import java.util.Objects;

public class Potion {
    private String name;
    private int price;
    private Status increasingStatus;

    public Potion(String name, int price, Status increasingStatus) {
        setName(name);
        if (price < 1) {
            setPrice(1);
        } else {
            setPrice(price);
        }
        this.increasingStatus = increasingStatus;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Potion potion = (Potion) o;
        return price == potion.price && Objects.equals(name, potion.name) && Objects.equals(increasingStatus, potion.increasingStatus);
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

    public Status getIncreasingStatus() {
        return increasingStatus;
    }

    public void setIncreasingStatus(Status increasingStatus) {
        this.increasingStatus = increasingStatus;
    }
}
