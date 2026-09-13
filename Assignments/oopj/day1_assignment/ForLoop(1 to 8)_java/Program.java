package java_program;

public class Program {
	static void evenPrint() {
		for(int tmp=1 ; tmp+tmp<=500 ; tmp++) {
			System.out.println(tmp+tmp);
		}
	}
	static void oddPrint() {
		for(int iTmp=0 ; iTmp+iTmp+1<=1000 ; iTmp++) {
			System.out.println(iTmp+iTmp+1);
		}
	}
	static void seventhNumber() {
		for(int tmp = 1 ; tmp*7<=200 ; tmp++) {
			System.out.println(tmp*7);
		}
	}
	static void pattern() {
		for(int tmp=0 ; tmp<5 ; tmp++) {
			for(int jTmp = 0 ; jTmp<=tmp ; jTmp++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
	static void revPattern() {
		for(int tmp=5 ; tmp>0 ; tmp--) {
			for(int jTmp = 0; jTmp<tmp ; jTmp++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
	static void numPattern() {
		int num=1;
		for(int tmp=1; tmp<6 ; tmp++) {
			for(int jTmp=1 ; jTmp<tmp ; jTmp++) {
				System.out.print(num + " ");
				num++;
			}
			System.out.println();
		}
	}
	static void numPattern2() {
		for(int tmp=1 ; tmp<7 ; tmp++) {
			for(int jTmp=1 ; jTmp<=tmp ; jTmp++) {
				System.out.print(jTmp + " ");
			}
			System.out.println();
		}
	}
	static void numPattern3() {
		for(int tmp=7 ; tmp>=1 ; tmp--) {
			for(int jTmp=1 ; jTmp<tmp ; jTmp++) {
				System.out.print(jTmp + " ");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		oddPrint();
		evenPrint();
		seventhNumber();
		pattern();
		revPattern();
		numPattern();
		numPattern2();
		numPattern3();
		}
	
}

