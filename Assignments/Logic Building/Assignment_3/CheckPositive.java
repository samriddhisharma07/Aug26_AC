import java.util.Scanner;
class CheckPositive{
	void askForPositiveNumber(){
		int num = 0;
						
		do{

			Scanner scanner = new Scanner(System.in);
			System.out.print("Enter a positive number : ");			
			num = scanner.nextInt();
			if(num>=0){
				System.out.print("You entered a positive number: " + num);
				break;	
			}
			
			
	    } while(num<0);
	    		
			
	}

	public static void main(String[] args){
		
		
		CheckPositive c1 = new CheckPositive();
		
		c1.askForPositiveNumber();
		

		
	}
}