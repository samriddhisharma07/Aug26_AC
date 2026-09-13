package java_work;

public class ArrayDuplicate1 {

    public static void main(String[] args) {

        int[] arr = {5, 2, 8, 2, 3, 5};

        for(int tmp = 0; tmp < arr.length; tmp++) {

            for(int jTmp = i + 1; jTmp < arr.length; jTmp++) {

                if(arr[tmp] == arr[jTmp]) {
                    System.out.println("Duplicate = " + arr[tmp]);
                }
            }
        }
    }
}
