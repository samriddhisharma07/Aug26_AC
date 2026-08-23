import java.util.Scanner;
class CalcFactorial{


	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int num = scanner.nextInt();
		int total = 1;
		for(int i=total ; i<=num ; i++){
			total = total*i;			
		}
		System.out.println("Factorial of " + num + " is " + total);
	}

}