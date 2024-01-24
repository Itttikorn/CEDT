public class Circle extends Shape{
    double radius;

    @Override
    double getArea() {
        return Math.PI*Math.pow(radius,2);
    }

    @Override
    double getPerimeter() {
        return 2*Math.PI*radius;
    }

    public Circle(double radius) {
        this.radius = radius;
    }
}
