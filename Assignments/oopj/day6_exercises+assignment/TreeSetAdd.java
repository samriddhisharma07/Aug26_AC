package java_newAssignment;
import java.util.TreeSet;
public class TreeSetAdd {
    public static void main(String[] args) {
        TreeSet<String> colors1 = new TreeSet<String>();
        colors1.add("Red");
        colors1.add("Blue");
        colors1.add("Green");
        TreeSet<String> colors2 = new TreeSet<String>();
        colors2.add("Black");
        colors2.add("Yellow");
        colors2.addAll(colors1);
        System.out.println(colors2);
    }
}
