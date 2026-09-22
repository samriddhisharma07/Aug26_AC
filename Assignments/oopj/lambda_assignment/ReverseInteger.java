package lambda_assignment;
import java.util.function.Function;
import java.util.Arrays;
public class ReverseInteger {
	public static void main(String[] args) {
        Function<Integer[], Integer[]> f = (arr) -> {
            Integer[] rev = new Integer[arr.length];
            for (int i = 0; i < arr.length; i++) {
                rev[i] = arr[arr.length - 1 - i];
            }
            return rev;
        };
        Integer[] arr = {1, 2, 3, 4, 5};
        Integer[] result = f.apply(arr);
        System.out.println(Arrays.toString(result));
    }
}
