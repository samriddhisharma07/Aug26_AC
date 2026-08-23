import java.util.*;
class StringLiteralConcept {

	public static void main(String[] args){
		String str1 = new String ("hello");
		String str2 = new String ("hello");
		
		if(str1==str2){
			System.out.println("Using ==: true");
		}
		else{
			System.out.println("Using ==: false");

		}
		if(str1.equals(str2)){
			System.out.println("Using .equals(): true");
		}
		else{
			System.out.println("Using .equals(): false");

		}

	}

}