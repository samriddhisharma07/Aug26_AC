import java.util.Scanner;
import java.util.Arrays;

class CalcArraySum{


	public static void main (String[] args){
	
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter 5 integers: ");

		int[] sum = new int[5];
		int total = 0;
				
		for(int s : sum){
			sum[s] = scanner.nextInt();
			total += sum[s];
		}
		System.out.println("The sum of all numbers is: " + total);

		scanner.close();

	
	}
	
}