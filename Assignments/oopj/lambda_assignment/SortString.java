package lambda_assignment;
import java.util.Comparator;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;
public class SortString {
	public static void main(String[] args) {
		String[] arr = {"banana" , "grapes" , "apple" , "orange"};
		Comparator<String>c = (a,b)->a.compareToIgnoreCase(b);
		Arrays.sort(arr,c);
		System.out.println(Arrays.toString(arr));
	}
}

