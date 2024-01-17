import java.util.Objects;

public class Dice {
    public static int MAX_VALUE = 6;
    private int faceValue;

    public Dice(int faceValue) {
        this.faceValue = faceValue;
    }

    public int getFaceValue() {
        return faceValue;
    }

    public void setFaceValue(int faceValue) {
        if (faceValue < 1) this.faceValue = 1;
        else if (faceValue > MAX_VALUE) this.faceValue = MAX_VALUE;
        else this.faceValue = faceValue;
    }

    @Override
    public String toString() {
        return "Dice{" +
                "faceValue=" + faceValue +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Dice dice = (Dice) o;
        return getFaceValue() == dice.getFaceValue();
    }

    @Override
    public int hashCode() {
        return Objects.hash(getFaceValue());
    }
}