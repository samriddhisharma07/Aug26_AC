import java.util.Scanner;
class Multiplication{


	static void printMultiplicationTable(){

		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter no.: ");
		int num = scanner.nextInt();
	
		for(int i=1; i<=10; i++){
			
			int result = num * i;
			System.out.println(num + " * " + i + " = " + result);
			
		}
	
	}

	public static void main(String[] args){
		
		printMultiplicationTable();

	
	}

}