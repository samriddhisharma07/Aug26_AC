package java_work;

public class ArrayReverse {

    public static void main(String[] args) {

        int[] arr = {5, 2, 8, 1, 3};

        for(int i = 0; i < arr.length / 2; i++) {

            int temp = arr[i];
            arr[i] = arr[arr.length - 1 - i];
            arr[arr.length - 1 - i] = temp;
        }

        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
