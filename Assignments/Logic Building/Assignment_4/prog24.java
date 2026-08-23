import java.util.*;
class ReverseString {
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String name = scanner.nextLine();
		String reversed="";
		
		for(int i=name.length()-1 ; i>=0 ; i--){
			reversed = reversed + name.charAt(i);
		}
		System.out.print("Reversed string: " + reversed);

		

	
	}

}