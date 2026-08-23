import java.util.Scanner;
import java.util.Arrays;

class CountNum{


	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter 6 integers: ");
		int[] nums = new int[6];

		int pcount = 0;
		int ncount=0;

		
		for(int i=0 ; i<6 ; i++){
			nums[i] = scanner.nextInt();
			if(nums[i]>0){
				pcount++;
			}
			else{
				ncount++;
				
			}
						
		}
		System.out.println("Positive numbers: " + pcount);
		System.out.println("Negative numbers: " + ncount);
		
	}
}
