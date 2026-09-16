import java.util.Scanner;
public class Test {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("enter : ");
		String data = scanner.nextLine();
		for(int tmp=0; tmp<data.length() ; tmp++) {
			if(tmp==0) {
				System.out.println("The character at position " + i + " is " +data.charAt(tmp) );
			}else if(tmp==10) {
				System.out.println("The character at position " + i + " is "+data.charAt(tmp));
			}
		}
	}
}
