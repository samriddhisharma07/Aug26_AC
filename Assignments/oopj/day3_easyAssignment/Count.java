import java.util.Scanner;

public class Count {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        String data = scanner.nextLine();

        for(char tmp = 'a'; tmp <= 'j'; tmp++) {
            System.out.print(tmp + " ");
        }

        System.out.println();
        System.out.println("=========================");

        for(char tmp = 'a'; tmp <= 'j'; tmp++) {
            System.out.print(data.indexOf(tmp) + " ");
        }

        System.out.println("\n");

        for(char tmp = 'k'; tmp <= 't'; tmp++) {
            System.out.print(tmp + " ");
        }

        System.out.println();
        System.out.println("=========================");

        for(char tmp = 'k'; tmp <= 't'; tmp++) {
            System.out.print(data.indexOf(tmp) + " ");
        }

        System.out.println("\n");

        for(char tmp = 'u'; tmp <= 'z'; tmp++) {
            System.out.print(tmp + " ");
        }

        System.out.println();
        System.out.println("================");

        for(char tmp = 'u'; tmp <= 'z'; tmp++) {
            System.out.print(data.indexOf(tmp) + " ");
        }
    }
}