
public class Reverse {
    public static void main(String[] args) {

        String data = "The quick brown fox jumps";

        System.out.println("The given string is: " + data);
        System.out.println("The string in reverse order is:");

        for(int tmp = data.length() - 1; tmp >= 0; tmp--) {
            System.out.print(data.charAt(tmp));
        }
    }
}
