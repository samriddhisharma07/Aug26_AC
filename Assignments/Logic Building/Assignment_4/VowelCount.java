import java.util.*;

class VowelCount{
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String name = scanner.next();
		String lowerName = name.toLowerCase();
		
		int count=0;
		for(int i=0 ; i<=lowerName.length()-1 ; i++){
			switch(lowerName.charAt(i)){
			case 'a' , 'e' , 'i' , 'o' , 'u' ->{
							     count++;
							   }
			}
		}
		System.out.print("The number of vowels in " + "\'" + name +"\' "+ "is: " + count);

	}

}