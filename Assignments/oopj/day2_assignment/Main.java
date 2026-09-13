package java_mini_work;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        PrimeMembers p = new PrimeMembers();

        System.out.print("Enter Name: ");
        p.setName(sc.nextLine());

        System.out.print("Enter Age: ");
        p.setAge(sc.nextInt());

        sc.nextLine();

        System.out.print("Enter Phone: ");
        p.setPhone(sc.nextLine());

        System.out.print("Enter Address: ");
        p.setAddress(sc.nextLine());

        System.out.print("Enter Salary: ");
        p.setSalary(sc.nextDouble());

        System.out.print("Enter Joining Year: ");
        p.setJoiningYear(sc.nextInt());

        System.out.print("Enter Joining Fees: ");
        p.setJoiningFees(sc.nextDouble());

        System.out.print("Is Active (true/false): ");
        p.setActive(sc.nextBoolean());

        System.out.println("\n--- Member Details ---");
        p.display();

        p.printSalary();

        sc.close();
    }
}