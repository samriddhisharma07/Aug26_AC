package java_mini_work;

public class Rectangle {

    private double length;
    private double breadth;

    Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public void area() {
        System.out.println("Rectangle Area = " + (length * breadth));
    }

    public void perimeter() {
        System.out.println("Rectangle Perimeter = " + (2 * (length + breadth)));
    }
}