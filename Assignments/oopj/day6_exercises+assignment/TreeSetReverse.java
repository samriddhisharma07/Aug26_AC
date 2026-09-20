package java_newAssignment;
import java.util.TreeSet;
public class TreeSetReverse {
    public static void main(String[] args) {
        TreeSet<String> colors = new TreeSet<String>();
        colors.add("Red");
        colors.add("Blue");
        colors.add("Green");
        colors.add("Black");
        colors.add("Yellow");
        System.out.println(colors.descendingSet());
    }
}
