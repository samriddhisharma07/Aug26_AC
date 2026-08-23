import java.util.Scanner;
class Main{
	byte a;
    	short b;
    	int c;
    	long d;
    	float e;
    	double f;
    	char g;
    	boolean h;


	public static void main(String[] args){
		
		int choice;	
	
		do{
			
			Scanner scanner = new Scanner(System.in);
			System.out.println("Enter which problem you want to solve");
			System.out.println("Problem 1: Grade Evaluation System \nProblem 2: Leap Year Check \nProblem 3: Day of the week \nProblem 4: Identify Default Values of Variables \nProblem 5: Exit");
			System.out.print("Enter your choice (1 to 5): ");

			choice = scanner.nextInt();

		

			switch(choice){
			case 1 : 
				{
			
					System.out.println("Enter marks of Maths: ");
					int m1 = scanner.nextInt();
					System.out.println("Enter marks of Science: ");
					int s1 = scanner.nextInt();
					System.out.println("Enter marks of History: ");
					int h1 = scanner.nextInt();
					int avg = ((m1+s1+h1)/3);
					if(avg>=90){
						System.out.println("Grade A");
						
					} 
					else if(avg>=70){
						System.out.println("Grade B");
						
					}
					else if(avg>=50){
						System.out.println("Grade C");
						
					}
					else if(avg>=30){
						System.out.println("Grade D");
						
					}
					else{
						System.out.println("Fail");
						

					}
					break;
					
				
				}
			case 2 : 
				{
					System.out.println("Enter a year you want to check : ");
					int y1 = scanner.nextInt();
		
				
					if(y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0){
						System.out.println(y1 + " is a leap year");
					}
					else{
					System.out.println(y1 + " is not a leap year");

					}
					break;

				}
			case 3 :
				{
					System.out.println("Enter number : ");
					int dayNumber = scanner.nextInt();

					switch(dayNumber){
						case 1 -> System.out.println("The day is Monday");
						case 2 -> System.out.println("The day is Tuesday");
						case 3 -> System.out.println("The day is Wednesday");
						case 4 -> System.out.println("The day is Thursday");
						case 5 -> System.out.println("The day is Friday");
						case 6 -> System.out.println("The day is Saturday");
						case 7 -> System.out.println("The day is Sunday");
						default -> System.out.println("Invalid day number");
					}
					break;
				}

			case 4 : 
				{
					Main obj = new Main();
					System.out.println("byte: " + obj.a);
					System.out.println("short: " + obj.b);
					System.out.println("int: " + obj.c);
					System.out.println("long: " + obj.d);
					System.out.println("float: " + obj.e);
					System.out.println("double: " + obj.f);
					System.out.println("char: " + obj.g);
					System.out.println("boolean: " + obj.h);
					break;

				}
	
			default : 
			 	{
					break;
			 	}
		
			}
		}while(choice<5);

	
	}

}