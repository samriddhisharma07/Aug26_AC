import java.util.Scanner;
class Sum{
	

	static void calculateSum(){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a number : ");
		int num = scanner.nextInt();
		int total = 0;

		for(int i=total ; i<=num ; i++){
			total += i;
			
		}
		System.out.println("The sum of numbers from 1 to " + num + " is: " + total);
		
	}


	public static void main(String[] args){
		calculateSum();			
	
	}

}