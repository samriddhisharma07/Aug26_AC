package lambda_assignment;
import java.util.function.Predicate;
public class CheckPrimeNumber {
	public static void main(String[] args) {
		Predicate<Integer> p = num->{
            if (num <= 1) {
                return false;
            }
            for (int i = 2; i <= Math.sqrt(num); i++) {
                if (num % i == 0) {
                    return false; 
                }
            }
            return true; 
        };
        System.out.println(p.test(3));  
        System.out.println(p.test(9)); 
        System.out.println(p.test(1));  
        System.out.println(p.test(2)); 
	}
}
