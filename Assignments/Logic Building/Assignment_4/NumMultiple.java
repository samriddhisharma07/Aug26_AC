import java.util.Scanner;
class NumMultiple{

	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int num = scanner.nextInt();
		
		for(int i=1 ; i*3<num ; i++){
			System.out.println(3*i);
		}
		
			
	}

}