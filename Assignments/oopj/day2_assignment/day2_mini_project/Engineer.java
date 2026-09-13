package java_mini_project;

public class Engineer extends Employee {
    double technicalAllowance;

    void display() {
        System.out.println("Type    : Engineer");
        System.out.println("Name    : " + name);
        System.out.println("Address : " + address);
        System.out.println("Age     : " + age);
        System.out.println("Gender  : " + gender);
        System.out.println("Salary  : " + basicSalary);
        System.out.println("Allowance : " + technicalAllowance);
    }

    String toFileLine() {
        return "ENGINEER," + name + "," + address + "," + age + "," + gender + "," + basicSalary + "," + technicalAllowance;
    }
}