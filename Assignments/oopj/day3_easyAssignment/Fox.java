public class Fox {
    public static void main(String[] args) {

        String data = "The quick brown fox jumps over the lazy dog.";

        String newData = data.replaceAll("fox", "cat");

        System.out.println("Original string: " + data);
        System.out.println("New String: " + newData);
    }
}
