import java.util.*;

class IndexOfElement{
	
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
				int result = numList.indexOf(n);
				System.out.println("The number " + n + " is found at index: " + result);
				break;
			}
		}
	
	}






}