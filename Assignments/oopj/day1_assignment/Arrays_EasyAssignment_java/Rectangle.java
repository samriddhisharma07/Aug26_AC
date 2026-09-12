package java_work;

public class Rectangle {
	
	int length;
	int breadth;
	Rectangle(int l , int b){
		length = l;
		breadth = b;
	}
	int area(){
		return length*breadth;
	
	}
	public static void main(String[] args) {
		Rectangle r = new Rectangle(4,5);
		Rectangle r1 = new Rectangle(5,8);
		System.out.println(r.area());
		System.out.println(r1.area());
		
	}

}
