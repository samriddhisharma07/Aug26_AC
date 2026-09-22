package lambda_assignment;
import java.util.Comparator;
import java.util.Arrays;
public class SmallestInteger {
	public static void main(String[] args) {
		Integer[] arr = {23,1,56,2,9};
		Comparator<Integer> c = (a,b)->a-b;
		Arrays.sort(arr,c);
		System.out.println(arr[0]);
	}
}
