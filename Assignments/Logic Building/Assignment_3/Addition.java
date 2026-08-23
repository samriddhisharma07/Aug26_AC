import java.util.Scanner;
class Addition{
	
	int sumOfTwoNumbers(int a , int b){
		
		int sum = a + b;
		return sum;
		
	}

	public static void main(String[] args){
		
		Scanner scanner = new Scanner(System.in);

		Addition add = new Addition();

		System.out.print("Enter value of a : ");
		int a = scanner.nextInt();

		System.out.print("Enter value of b : ");
		int b = scanner.nextInt();

		
		int result = add.sumOfTwoNumbers(a , b);
		System.out.print("The sum of " + a + " and " + b + " is " + result);
		
		
		

	
	}



}