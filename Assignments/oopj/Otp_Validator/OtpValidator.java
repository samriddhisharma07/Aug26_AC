import java.util.function.Supplier;
public class OtpValidator {
	public static void main(String[] args) {
		Supplier<String>s = ()->{
			String v = "AEIOU";
			String otp="";
			char first = v.charAt((int)(Math.random()*5));
			otp = otp+first;
			for(int tmp=0;tmp<v.length() ; tmp++) {
				int n = (int)(Math.random()*10);
				otp = otp+n;
			}
			return otp;
		};
		System.out.println(s.get());
	}
}
