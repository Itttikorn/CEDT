package Exercise03;

import java.util.Scanner;

public class FoodOrder {

    // Fields: description, price, chicken, vegetable, extraChicken, extraRice
    // START CODE HERE
    private String description;
    private int price;
    private boolean hasChicken;
    private boolean hasVegetable;
    private boolean hasExtraChicken;
    private boolean hasExtraRice;
    // END CODE HERE

    // Constructor
    // START CODE HERE
    public FoodOrder() {
        setDescription("Hainanese Chicken Rice");
        setPrice(40);
        setHasChicken(true);
        setHasVegetable(true);
        setHasExtraChicken(false);
        setHasExtraRice(false);
    }
    // END CODE HERE

    // Methods
    // START CODE HERE

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        FoodOrder foodOrder = new FoodOrder();
        System.out.println("Hi, Welcome to Kao-Mun-Gai food stall!");
        System.out.println("We only sell " + foodOrder.getDescription());
        System.out.println("Would you like your meal with chicken? (Yes/No)");
        String customerInput = keyboard.next();
        if (customerInput.equals("No")) {
            foodOrder.setHasChicken(false);
            System.out.println("Okay...");
        } else if (customerInput.equals("Yes")) {
            foodOrder.setHasChicken(true);
        }
        System.out.println("Would you like your meal with vegetable? (Yes/No)");
        customerInput = keyboard.next();
        if (customerInput.equals("No")) {
            foodOrder.setHasVegetable(false);
        } else if (customerInput.equals("Yes")) {
            foodOrder.setHasVegetable(true);
        }
        System.out.println("Extra chicken? (Yes/No)");
        customerInput = keyboard.next();
        if (customerInput.equals("Yes")) {
            foodOrder.setHasExtraChicken(true);
            System.out.println("Good Choice!");
        } else if (customerInput.equals("No")) {
            foodOrder.setHasExtraChicken(false);
        }
        System.out.println("Extra Rice? (Yes/No)");
        customerInput = keyboard.next();
        if (customerInput.equals("Yes")) {
            foodOrder.setHasExtraRice(true);
        } else if (customerInput.equals("No")) {
            foodOrder.setHasExtraRice(false);
        }
        foodOrder.calculatePrice();
        System.out.println(foodOrder);

         //Uncomment the following lines to test equals method
         FoodOrder testOrder = new FoodOrder();
         testOrder.setHasChicken(false);
         testOrder.setHasExtraChicken(false);
         testOrder.setHasExtraRice(true);
         FoodOrder testOrder2 = new FoodOrder();
         testOrder2.setHasChicken(false);
         testOrder2.setHasExtraChicken(false);
         testOrder2.setHasExtraRice(true);
         System.out.println("Equal:" + testOrder.equals(testOrder2));
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public boolean isHasChicken() {
        return hasChicken;
    }

    public void setHasChicken(boolean hasChicken) {
        this.hasChicken = hasChicken;
    }

    public boolean isHasVegetable() {
        return hasVegetable;
    }

    public void setHasVegetable(boolean hasVegetable) {
        this.hasVegetable = hasVegetable;
    }

    public boolean isHasExtraChicken() {
        return hasExtraChicken;
    }

    public void setHasExtraChicken(boolean hasExtraChicken) {
        this.hasExtraChicken = hasExtraChicken;
    }

    public boolean isHasExtraRice() {
        return hasExtraRice;
    }

    public void setHasExtraRice(boolean hasExtraRice) {
        this.hasExtraRice = hasExtraRice;
    }
    // END CODE HERE

    public void calculatePrice() {
        if (!hasChicken) {
            setPrice(getPrice() - 10);
        }
        if (hasExtraChicken) {
            setPrice(getPrice() + 10);
        }
        if (hasExtraRice) {
            setPrice(getPrice() + 5);
        }
    }

    @Override
    public String toString() {
        // START CODE HERE
        return "That would be " + price + " baht. Thanks!" + "\n"
                + "Hainanese chicken rice" + "\n"
                + "Chicken: " + hasChicken + "\n"
                + "Vegetable: " + hasVegetable + "\n"
                + "Extra Chicken: " + hasExtraRice + "\n"
                + "Extra Rice: " + hasExtraRice;
        // END CODE HERE
    }

    @Override
    public boolean equals(Object other) {
        // START CODE HERE
        if (other.getClass() == getClass()) {
            return ((FoodOrder) other).getPrice() == getPrice();
        }
        return false;
        // END CODE HERE
    }

}
