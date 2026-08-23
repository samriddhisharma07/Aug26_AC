class PatternPrint{

	public static void main(String[] args){
		for(int i=0 ; i<=5 ; i++){
			for(int j=1 ; j<i+1 ; j++){
				System.out.print(j);
				if(j<i){
					System.out.print("*");
				}
			}
			System.out.println();
		}
	}
}