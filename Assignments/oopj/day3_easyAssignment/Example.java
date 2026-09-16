import java.util.Scanner;
public class Example {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String data = "";
		while(!data.endsWith("se")) {
			System.out.println("enter the value : ");
			data = scanner.nextLine();
			if(data.endsWith("se") ) {
				System.out.println("\""+data +"\""+ " ends with \"se?\" "+"true");
			}else {
				System.out.println("\""+data +"\""+ " ends with \"se?\" "+"false");
			}
		}
	}
}
