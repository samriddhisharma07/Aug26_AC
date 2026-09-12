package java_work;

public class Complex {
	int num1;
	int num2;
	Complex(int n1 , int n2){
		num1 = n1;
		num2 = n2;
	}
	Complex add(Complex c) {
		return new Complex(num1+c.num1 , num2+c.num2);
	}
	Complex substract(Complex c) {
		return new Complex(num1-c.num1 , num2-c.num2);
	}
	Complex multiply(Complex c) {
		return new Complex(
			    num1*c.num1 - num2*c.num2,
			    num1*c.num2 + num2*c.num1
			);
	}
	public String toString() {
	    return num1 + " + " + num2 + "i";
	}
	public static void main(String[] args) {
		Complex complex = new Complex(4,5);
		Complex complex1 = new Complex(6,2);
		System.out.println(complex.add(complex1));
		System.out.println(complex.substract(complex1));
		System.out.println(complex.multiply(complex1));
		
	}
}
