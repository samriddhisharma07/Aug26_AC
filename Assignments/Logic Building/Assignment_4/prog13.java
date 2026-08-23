import java.util.Scanner;
import java.util.Arrays;
import java.util.List;


class CheckElement{


	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter 5 integers: ");
		Integer[] nums = new Integer[5];
		
		for(int i=0 ; i<5 ; i++){
			nums[i] = scanner.nextInt();				
		}

		List<Integer> numList = Arrays.asList(nums);
		System.out.print("Enter the number to search: ");
		for(Integer n:numList){
			n = scanner.nextInt();
			if(numList.contains(n)){
				System.out.print("Found");
				break;
			}
			else{
				System.out.print("Not Found");
				break;
			}
			
		}
					
	}

}