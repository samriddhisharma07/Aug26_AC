class AvgMarks{
	
	public static void main(String[] args){
		int maths = 80;
		int science = 85;
		int history = 90;
		
		int avg = ((maths+science+history)/3);
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
		
	}

}