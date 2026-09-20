package java_newAssignment;
import java.util.ArrayList;
import java.util.Collections;
public class SortArrayList {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<String>();
        colors.add("Red");
        colors.add("Blue");
        colors.add("Green");
        colors.add("Black");
        colors.add("Yellow");
        System.out.println("Before sorting: " + colors);
        Collections.sort(colors);
        System.out.println("After sorting: " + colors);
    }
}
