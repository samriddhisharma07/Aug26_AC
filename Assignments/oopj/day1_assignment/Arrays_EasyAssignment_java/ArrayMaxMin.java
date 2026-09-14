package java_work;

public class ArrayMaxMin {

    public static void main(String[] args) {

        int[] arr = {5, 2, 8, 1, 3};

        int max = arr[0];
        int min = arr[0];

        for(int tmp = 1; tmp < arr.length; tmp++) {

            if(arr[tmp] > max) {
                max = arr[tmp];
            }

            if(arr[tmp] < min) {
                min = arr[tmp];
            }
        }

        System.out.println("Maximum = " + max);
        System.out.println("Minimum = " + min);
    }
}
