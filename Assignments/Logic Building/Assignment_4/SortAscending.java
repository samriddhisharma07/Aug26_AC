import java.util.Scanner;
import java.util.Arrays;

class SortAscending{


	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter 5 integers: ");
		int[] nums = new int[5];
		
		for(int i=0 ; i<5 ; i++){
			nums[i] = scanner.nextInt();
		}
		Arrays.sort(nums);
		System.out.print("Sorted array: " + Arrays.toString(nums));
		
	}
}