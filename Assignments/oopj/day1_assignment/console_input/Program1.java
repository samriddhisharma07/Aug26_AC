
public class Program1 {

    public static void main(String[] args)
    {
        System.out.println("Enter first number");
        int a = ConsoleInput.getInt();

        System.out.println("Enter second number");
        int b = ConsoleInput.getInt();

        int c = a + b;

        System.out.println("Addition = " + c);
    }
}