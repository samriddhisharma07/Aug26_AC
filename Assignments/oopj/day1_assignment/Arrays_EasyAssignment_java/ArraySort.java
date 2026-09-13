package java_work;

public class ArraySort {

    public static void main(String[] args) {
        int[] arr = {5, 2, 8, 1, 3};
        for(int tmp = 0; tmp < arr.length; tmp++) {
            for(int jTmp = tmp + 1; jTmp < arr.length; jTmp++) {
                if(arr[tmp] > arr[jTmp]) {
                    int temp = arr[tmp];
                    arr[tmp] = arr[jTmp];
                    arr[jTmp] = temp;
                }
            }
        }
        for(int tmp = 0; tmp < arr.length; tmp++) {
            System.out.print(arr[tmp] + " ");
        }
    }
}
