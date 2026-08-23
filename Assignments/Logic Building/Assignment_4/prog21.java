class NumberPattern{
	public static void main(String[] args){
		int total=0;
		for(int i=1 ; i<=5 ; i++){
			for(int j=1 ; j<=i ; j++){
				total = total+1;
				System.out.print(total);
				if(j<i){
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}

}