import java.util.Scanner;
class Age{

	String checkAgeCategory(int age){
		if(age<18){
			return "m";
		}
		else if(age>=18 && age<=59){
			return "a";
		}
		else{
			return "sc";
		}
		//String answer = (age<18)? "Minor" : (age>=18 && age<=59)? "Adult" : "Senior Citizen";
		//return answer;	
	}

	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		Age a1 = new Age();

		System.out.println("Enter your age: ");
		int age = scanner.nextInt();

		String result = a1.checkAgeCategory(age);
		System.out.println("You are an " + result);
		
		
	}


}