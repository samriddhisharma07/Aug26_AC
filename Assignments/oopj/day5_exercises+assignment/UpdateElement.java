package java_ArrayList;

import java.util.ArrayList;
import java.util.Iterator;
public class UpdateElement {
	public static void main(String[] args) {
		ArrayList <String> colors = new ArrayList<String>();
		colors.add("Blue");
		colors.add("Red");
		colors.add("Orange");
		
		int data = colors.indexOf("Blue");
		colors.set(data, "Yellow");
		Iterator iterator = colors.iterator();
		while(iterator.hasNext()) {
			String value = (String)iterator.next();
			System.out.println(value);
		}
	}
}
