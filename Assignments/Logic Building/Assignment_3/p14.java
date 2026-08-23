class Even{

	void printEvenNumber(){
		int i=2;
		while(i<=50){
			
			System.out.print(i + " ");
			i+=2;
		}
	}


	public static void main(String[] args){
		Even e1 = new Even();
		e1.printEvenNumber();	
	
	}
}