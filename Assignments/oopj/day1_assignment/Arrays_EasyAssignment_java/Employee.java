package java_work;

public class Employee {
	String name;
	int year_of_joining;
	int salary;
	String address;
	int working_hour;
	Employee(String n ,int y, int s, String a){
		name = n;
		year_of_joining = y;
		salary = s;
		address = a;
	}
	int getInfo(int s,int w) {
		salary = s;
		working_hour = w;
		return salary;	
	}
	int addSal(int salary) {
		if(salary<500) {
			return salary+10;
		}
		return salary;
		
	}
	int addWork(int working_hour) {
		if(working_hour>6) {
			return salary+5;
		}
		return salary;
		
	}
	void display() {
		System.out.println(name+ " " + year_of_joining + " " + address);
	}
	public String toString() {
	    return name + "\t\t" + year_of_joining + "\t\t\t" + salary + "\t\t" + address;
	}

    public static void main(String[] args) {

        Employee employee = new Employee("Robert", 1994, 50000, "64C- WallsStreat");
        Employee employee1 = new Employee("Sam", 2000, 55000, "68D- WallsStreat");
        Employee employee2 = new Employee("John", 1999, 60000, "26B- WallsStreat");

        System.out.println("Name\t\tYear of joining\t\tSalary\t\tAddress");

        System.out.println(employee);
        System.out.println(employee1);
        System.out.println(employee2);

    }
}
