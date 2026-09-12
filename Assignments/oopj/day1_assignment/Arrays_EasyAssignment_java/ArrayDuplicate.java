package java_work;

public class ArrayDuplicate {

    public static void main(String[] args) {

        int[] arr = {5, 2, 8, 2, 3, 5};

        for(int i = 0; i < arr.length; i++) {

            for(int j = i + 1; j < arr.length; j++) {

                if(arr[i] == arr[j]) {
                    System.out.println("Duplicate = " + arr[i]);
                }
            }
        }
    }
}
