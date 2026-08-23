import java.util.*;

class StringDemo{

	public static void main(String[] args){
		String str1 = new String("hello");
		String str2 = str1.intern();
		String str3 = "hello";

		if(str2 == str3){
			System.out.println("Is str2 and str3 pointing to the same object? true");
		}
		else{
			System.out.println("Is str2 and str3 pointing to the same object? false");

		}
	}	
	
}