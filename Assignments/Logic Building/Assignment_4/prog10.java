import java.util.Scanner;
import java.util.Arrays;

class CalcAvg{


	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter 5 integers: ");
		int[] num = new int[5];
		int total=0;
		for(int i=total ; i<5 ; i++){
			num[i] = scanner.nextInt();
			total = total+ num[i];
			
		}
		System.out.println("The average of the numbers is: " + total/5.0);

	}
}