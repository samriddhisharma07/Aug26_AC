import java.util.Scanner;
import java.util.Arrays;

class PrintUserNames{


	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter 4 names: ");
		
		String[] names = new String[4];

		for(int i=0 ; i<4 ; i++){
			names[i] = scanner.next();
		}
		
		for(String n : names){
			System.out.println(n);
		}

		scanner.close();
	

	}

}