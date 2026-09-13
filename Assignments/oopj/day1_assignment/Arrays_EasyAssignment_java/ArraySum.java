package java_work;

public class ArraySum {

    public static void main(String[] args) {
        int[] arr = {5, 2, 8, 1, 3};
        int sum = 0;
        for(int tmp = 0; tmp < arr.length; tmp++) {
            sum = sum + arr[tmp];
        }
        System.out.println("Sum = " + sum);
    }
}
