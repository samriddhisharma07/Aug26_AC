public class Program1 {

    public static void main(String[] args)
    {
        System.out.println("Enter first number");
        int a = ConsoleInput.getInt();

        System.out.println("Enter second number");
        int b = ConsoleInput.getInt();

        System.out.println("Addition = " + (a + b));
        System.out.println("Subtraction = " + (a - b));
        System.out.println("Multiplication = " + (a * b));
        System.out.println("Division = " + (a / b));
    }
}

