package java_mini_project;

public class SalesPerson extends Employee {
    double commission;

    void display() {
        System.out.println("Type    : Sales Person");
        System.out.println("Name    : " + name);
        System.out.println("Address : " + address);
        System.out.println("Age     : " + age);
        System.out.println("Gender  : " + gender);
        System.out.println("Salary  : " + basicSalary);
        System.out.println("Commission : " + commission);
    }

    String toFileLine() {
        return "SALESPERSON," + name + "," + address + "," + age + "," + gender + "," + basicSalary + "," + commission;
    }
}