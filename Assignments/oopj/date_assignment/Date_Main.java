package practice_employee;
import java.util.Scanner;
public class Date_Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		Date obj = new Date();

		System.out.println("Enter your date: ");

		int date = sc.nextInt();
		int month = sc.nextInt();
		int year = sc.nextInt();

		obj.setDate(date, month, year);

		System.out.println(obj.getDay() + "/" + obj.getMonth() + "/" + obj.getYear());

		obj.addDays(1234);

		obj.addMonth(12);

		System.out.println();

		System.out.println(obj.getDay() + "/" + obj.getMonth() + "/" + obj.getYear());

		sc.close();
	}
}

