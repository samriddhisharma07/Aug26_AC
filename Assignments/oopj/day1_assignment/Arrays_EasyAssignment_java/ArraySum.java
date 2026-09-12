package java_work;

public class ArraySum {

    public static void main(String[] args) {
        int[] arr = {5, 2, 8, 1, 3};
        int sum = 0;
        for(int i = 0; i < arr.length; i++) {
            sum = sum + arr[i];
        }
        System.out.println("Sum = " + sum);
    }
}
