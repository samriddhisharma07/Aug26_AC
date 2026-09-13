package java_mini_project;

public class Manager extends Employee {
    double hra;

    void display() {
        System.out.println("Type    : Manager");
        System.out.println("Name    : " + name);
        System.out.println("Address : " + address);
        System.out.println("Age     : " + age);
        System.out.println("Gender  : " + gender);
        System.out.println("Salary  : " + basicSalary);
        System.out.println("HRA     : " + hra);
    }

    String toFileLine() {
        return "MANAGER," + name + "," + address + "," + age + "," + gender + "," + basicSalary + "," + hra;
    }
}