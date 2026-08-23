import java.util.*;

class CheckPalindrome{


	public static void main (String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String name = scanner.next();
		String rev = "";
		for(int i=name.length()-1 ; i>=0 ; i--){
			rev = rev + name.charAt(i);
			
		}
		
		if(rev.equals(name)){
			System.out.print("The string" + " \'" + name + "\'" + " is a palindrome.");

		}
		else{
			System.out.print("The string" + " \'" + name + "\'" + " is not a palindrome.");

		}
		
	}

}