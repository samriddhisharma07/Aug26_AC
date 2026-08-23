class DayNumberCount{
	
	public static void main(String[] args){

		int dayNumber = 3;

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
		
	}
}