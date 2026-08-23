import java.util.Scanner;
class CalcSumOfOdd{


	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int num = scanner.nextInt();
		int sum = 0;

		for(int i=sum ; i*2+1<=num ; i++){
			sum = sum + (i*2+1);	
		}
		System.out.println("The sum of odd numbers from 1 to " + num + " is: "+ sum);

	}

}