package java_ArrayList;
import java.util.ArrayList;
import java.util.Iterator;
public class Colors {
	public static void main(String[] args) {
		ArrayList<String>colors = new ArrayList<String>();
		colors.add("Red");
		colors.add("Blue");
		colors.add("Orange");
		Iterator iterator = colors.iterator();
		while(iterator.hasNext()) {
			String data = (String)iterator.next();
			System.out.println(data);
		}
	}
}
