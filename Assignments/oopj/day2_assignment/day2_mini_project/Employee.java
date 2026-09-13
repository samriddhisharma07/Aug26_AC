package java_mini_project;

public abstract class Employee {
    String name;
    String address;
    int age;
    String gender;
    double basicSalary;

    void setData(String name, String address, int age, String gender, double basicSalary) {
        this.name = name;
        this.address = address;
        this.age = age;
        this.gender = gender;
        this.basicSalary = basicSalary;
    }

    abstract void display();

    abstract String toFileLine();
}