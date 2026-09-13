package java_mini_work;

public class Parent {
	void display() {
		System.out.println("method of parent class by object of child class");
	}
	void show() {
		System.out.println("method of parent class by object of parent class");
	}
	public static void main(String[] args) {
		System.out.println("This is parent class");
		Parent parent = new Parent();
		parent.show();
	}
}
