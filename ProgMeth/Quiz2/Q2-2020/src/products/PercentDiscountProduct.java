package products;

import discount.PercentDiscountable;
import logic.ShopUtil;

public class PercentDiscountProduct extends BaseProduct implements PercentDiscountable {
    private double percent;

    public PercentDiscountProduct(String name, int price, double percent) {
        super(name, price);
        setPercent(percent);
    }

    public double getPercent() {
        return percent;
    }

    public void setPercent(double percent) {
        if (percent < 0) percent = 0;
        if (percent > 100) percent = 100;
        this.percent = percent;
    }

    @Override
    public int calcDiscountPerPiece() {
        return ShopUtil.calculateDiscountUsingPercent(price, percent);
    }

    @Override
    public int calculateDiscount(int quantity) {
        return quantity * calcDiscountPerPiece();
    }

    @Override
    public String toString() {
        return this.getProductName() + " (Price: " + this.getPrice() + ", " + this.getPercent() + "% Off)";
    }
}
