import java.util.Scanner;
public class Code {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String input1 = scan.nextLine();
		String input2 = scan.nextLine();
		if(input1.contentEquals(input2)) {
			System.out.println(input1 +  "equals" + input2);
		}else {
			System.out.println("\""+input1+"\""+  " is less than " +"\""+ input2+"\"");
		}
	}
}
