package java_work;

public class ArrayCopy {

    public static void main(String[] args) {
        int[] arr = {5, 2, 8, 1, 3};
        int[] arr2 = new int[arr.length];
        for(int tmp = 0; tmp < arr.length; tmp++) {
            arr2[tmp] = arr[tmp];
        }
        for(int tmp = 0; tmp < arr2.length; tmp++) {
            System.out.print(arr2[tmp] + " ");
        }
    }
}
