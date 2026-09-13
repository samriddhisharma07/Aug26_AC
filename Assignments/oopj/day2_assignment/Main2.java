package java_mini_work;

import java.util.Scanner;

public class Main2 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Rectangle Length: ");
        double l = sc.nextDouble();

        System.out.print("Enter Rectangle Breadth: ");
        double b = sc.nextDouble();

        Rectangle r = new Rectangle(l, b);

        r.area();
        r.perimeter();

        System.out.print("\nEnter Square Side: ");
        double s = sc.nextDouble();

        Square sq = new Square(s);

        sq.area();
        sq.perimeter();

        sc.close();
    }
}