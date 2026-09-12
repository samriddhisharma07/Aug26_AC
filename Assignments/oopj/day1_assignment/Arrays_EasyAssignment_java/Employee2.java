package java_work;

public class Employee2 {
	int salary;
	int working_hour;

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
	public static void main(String[] args) {

	    Employee2 employee = new Employee2();
	    employee.getInfo(450, 7);
	    employee.salary = employee.addSal(employee.salary);
	    employee.salary = employee.addWork(employee.working_hour);
	    System.out.println("Final Salary : $" + employee.salary);
	}	
        
}
