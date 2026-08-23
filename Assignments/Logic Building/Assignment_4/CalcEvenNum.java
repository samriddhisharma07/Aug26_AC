import java.util.Scanner;
class CalcEvenNum{


	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int num = scanner.nextInt();

		// FIRST APPROACH
		
		//for(int i=1 ; i*2<num ; i++){
		//	System.out.print(i*2 + " ");			
		//}

	
		// SECOND APPROACH

		for(int i=1 ; i+i<=num  ; i++){
			
			System.out.print(i+i + " ");
		}
	}

}