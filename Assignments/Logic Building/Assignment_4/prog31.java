import java.util.*;

class MultipleStringLiteral{


	public static void main(String[] args){
		String str1 = "java";
		String str2 = "java";
		String str3 = "java";
		
		if((str1 == str2) && (str2 == str3)){
			System.out.println("All strings point to the same object: true");
		}
		else{
			System.out.println("All strings point to the same object: false");

		}
	}

}