import java.util.Scanner;
class Age{

	String checkAgeCategory(int age){
		
		String answer = (age<18)? "Minor" : (age>=18 && age<=59)? "Adult" : "Senior Citizen";
		return answer;	
	}

	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		Age a1 = new Age();

		System.out.print("Enter your age: ");
		int age = scanner.nextInt();

		String result = a1.checkAgeCategory(age);
		System.out.print("You are an " + result);
		
		
	}


}