package lambda_assignment;
import java.util.function.Supplier;
public class RandomNumGenerate {
	public static void main(String[] args) {
		Supplier<Integer>s = ()->{
			double num = (Math.random()*900+100);
			int result = (int)num;
			return result;
		};
		System.out.println(s.get());
	}
}
