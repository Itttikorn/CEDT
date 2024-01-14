package SelfTest;

import java.util.Objects;

public class Car {
    int serial;
    String brand;

    public Car(int x, String y){
        serial = x;
        brand = y;
    }

    public boolean equals(Object o){
        if (o instanceof Car) {
            Car c2 = (Car) o;
            return ((Car) o).serial == this.serial && ((Car) o).brand.equals(this.brand);

        } else {
            return false;
        }
    }
}
