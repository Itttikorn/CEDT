package SelfTest;

import java.util.ArrayList;

public class Garage {
    public Car[] cars;

    public void removeDup(){
        Car[] cars2 = new Car[cars.length];
        int i2 = 0;

        for (int i = 0; i < cars.length; i++) {
            boolean found = false;
            for(int j = 0;j<cars2.length;j++){
                if(cars[i].equals(cars2[j])){
                    found = true;
                }
            }
            if (!found) {
                cars2[i2++] = cars[i];
            }
        }

        int indexNull;
        for (indexNull = 0; indexNull < cars2.length; indexNull++) {
            if (cars2[indexNull] == null)
                break;
        }

        Car[] cars3 = new Car[indexNull];
        for (int i = 0; i < cars3.length; i++) {
            cars3[i] = cars2[i];
        }

        cars = cars3;
    }
}
