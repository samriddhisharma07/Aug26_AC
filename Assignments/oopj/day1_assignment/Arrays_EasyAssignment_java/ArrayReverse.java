package java_work;

public class ArrayReverse {

    public static void main(String[] args) {

        int[] arr = {5, 2, 8, 1, 3};

        for(int tmp = 0; tmp < arr.length / 2; tmp++) {

            int temp = arr[tmp];
            arr[tmp] = arr[arr.length - 1 - tmp];
            arr[arr.length - 1 - tmp] = temp;
        }

        for(int tmp = 0; tmp < arr.length; tmp++) {
            System.out.print(arr[tmp] + " ");
        }
    }
}
