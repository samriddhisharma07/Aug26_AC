package java_ArrayList;
import java.util.ArrayList;
import java.util.Iterator;
public class InsertElement {
	public static void main(String[] args) {
		ArrayList <String> colors = new ArrayList<String>();
		colors.add("Blue");
		colors.add("Red");
		colors.add("Orange");
		colors.add(0, "Black");
		Iterator iterator = colors.iterator();
		while(iterator.hasNext()) {
			String data = (String)iterator.next();
			System.out.println(data);
		}
	}
}
