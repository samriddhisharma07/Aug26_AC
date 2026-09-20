package java_newAssignment;
import java.util.ArrayList;
import java.util.Collections;
public class ShuffleArray {
    public static void main(String[] args) {
        ArrayList<String> colors = new ArrayList<String>();
        colors.add("Red");
        colors.add("Blue");
        colors.add("Green");
        colors.add("Black");
        colors.add("Yellow");
        System.out.println("Before shuffle: " + colors);
        Collections.shuffle(colors);
        System.out.println("After shuffle: " + colors);
    }
}

