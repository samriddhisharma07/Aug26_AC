import java.io.*;
import java.util.Scanner;

public abstract class SecretData {
	public static void main(String[] args) throws Exception{
		Scanner scan = new Scanner(System.in);
		int choice=0;
		while(choice!=3) {
			System.out.println("Enter your choice : 1.Encrypt 2.Decrypt 3.Exit");
			choice = scan.nextInt();
			EncryptDecrypt en = new EncryptDecrypt();
			if(choice==1) {
				scan.nextLine();
				en.encrypt();
				System.out.println("Encrypted successfully");
			}else if(choice==2) {
				scan.nextLine();
				en.decrypt();
				System.out.println("Decrypted successfully");
			}else if(choice==3) {
				scan.nextLine();
				System.out.println("Exiting..");
			}
			else {
				scan.nextLine();
				System.out.println("Invalid choice");
			}
		}
	}
}
