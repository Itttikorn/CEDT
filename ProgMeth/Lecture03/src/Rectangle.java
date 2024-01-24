public class Rectangle extends Shape {
    private double width;
    private double height;

    @Override
    double getArea() {
        return width * height;
    }

    @Override
    double getPerimeter() {
        return 2 * (width + height);
    }

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }
}
