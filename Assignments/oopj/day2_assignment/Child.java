package java_mini_work;

public class Child extends Parent{
	void show() {
		
		System.out.println("method of child class by object of child class");
	}
	public static void main(String[] args) {
		System.out.println("This is child class");
		Child child = new Child();
		child.show();
		child.display();
	}
}
