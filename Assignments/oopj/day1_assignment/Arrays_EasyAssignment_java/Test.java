package java_work;

public class Test {
	int s1 = 3;
	int s2 = 4;
	int s3 = 5;
	public static void main(String[] args) {
		Test test = new Test();
		double area = (0.5)*test.s1*test.s2;
		System.out.println(area);
		
		double perimeter = test.s1+test.s2+test.s3;
		System.out.println(perimeter);
	}
}