package java_mini_work;
public class PrimeMembers extends Member {

    private int joiningYear;
    private double joiningFees;
    private boolean isActive;

    public void setJoiningYear(int joiningYear) {
        this.joiningYear = joiningYear;
    }

    public int getJoiningYear() {
        return joiningYear;
    }

    public void setJoiningFees(double joiningFees) {
        this.joiningFees = joiningFees;
    }

    public double getJoiningFees() {
        return joiningFees;
    }

    public void setActive(boolean isActive) {
        this.isActive = isActive;
    }

    public boolean getActive() {
        return isActive;
    }

    public void display() {
        System.out.println("Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Phone: " + getPhone());
        System.out.println("Address: " + getAddress());
        System.out.println("Salary: " + getSalary());
        System.out.println("Joining Year: " + joiningYear);
        System.out.println("Joining Fees: " + joiningFees);
        System.out.println("Active: " + isActive);
    }
}