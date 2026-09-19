import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;
public class EncryptDecrypt extends SecretData{
	void encrypt() throws Exception{
		Scanner scan = new Scanner(System.in);
		FileWriter fw = new FileWriter("message.txt");
		String data = scan.nextLine();
		fw.write(data);
		fw.close();
		FileReader fr = new FileReader("message.txt");
		BufferedReader br = new BufferedReader(fr);
		FileWriter efw = new FileWriter("encrypted.txt");
		
		String line;
		if((line=br.readLine())!=null) {
			for(int tmp=0 ; tmp<line.length() ; tmp++) {
				char ch = line.charAt(tmp);
				ch = (char)(ch+1);
				efw.write(ch);
			}
		}
		efw.close();
		br.close();
	}
	void decrypt() throws Exception{
		FileReader fr = new FileReader("encrypted.txt");
		BufferedReader br = new BufferedReader(fr);
		
		FileWriter fw = new FileWriter("decrypted.txt");
		String line;
		if((line=br.readLine())!=null) {
			for(int tmp=0 ; tmp<line.length() ; tmp++) {
				char ch = line.charAt(tmp);
				ch = (char)(ch-1);
				fw.write(ch);
			}
		}
		fw.close();
		br.close();
	}
}
