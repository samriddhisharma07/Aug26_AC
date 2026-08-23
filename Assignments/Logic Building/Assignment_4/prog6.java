import java.util.Scanner;
import java.util.Arrays;

class PrintArray{

	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter 5 integers: ");

		int[] input = new int[5];
				
		for(int in: input){
			input[in] = scanner.nextInt();
			System.out.print(input[in] + " ");

		}
		
	}

}