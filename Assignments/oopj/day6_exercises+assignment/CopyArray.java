package java_newAssignment;
import java.util.ArrayList;
import java.util.Collections;
public class CopyArray {
    public static void main(String[] args) {

        ArrayList<String> colors = new ArrayList<String>();
        colors.add("Red");
        colors.add("Blue");
        colors.add("Green");
        colors.add("Black");

        ArrayList<String> colors2 = new ArrayList<String>();
        colors2.add("");
        colors2.add("");
        colors2.add("");
        colors2.add("");
        Collections.copy(colors2, colors);
        System.out.println(colors2);
    }
}

