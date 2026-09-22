package lambda_assignment;
import java.util.Arrays;
import java.util.Comparator;
public class LargestInteger {
	public static void main(String[] args) {
		Integer[] data = {23, 45, 78, 12};
        Comparator<Integer> c = (a, b) -> a - b;
        Arrays.sort(data, c);
        System.out.println(data[data.length - 1]);
	}
}
