import java.util.Scanner;
import java.util.Arrays;

class FindMaxNum{


	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter 5 integers: ");
		int[] nums = new int[5];
		int max = 0;

		for(int i=0 ; i<5 ; i++){
			nums[i] = scanner.nextInt();
		}
		Arrays.sort(nums);
		max = nums[nums.length - 1];
		System.out.print("The largest element is: " + max);		

	}

}