package java_newAssignment;
import java.util.TreeSet;
public class TreeSetCeiling {
    public static void main(String[] args) {
        TreeSet<Integer> numbers = new TreeSet<Integer>();
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        numbers.add(40);
        numbers.add(50);
        int n = 25;
        System.out.println(numbers.ceiling(n));
    }
}
