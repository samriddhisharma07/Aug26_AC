package java_ArrayList;

import java.util.ArrayList;
import java.util.Iterator;

public class RemoveThirdElement {
	public static void main(String[] args) {
		ArrayList <String> colors = new ArrayList<String>();
		colors.add("Blue");
		colors.add("Red");
		colors.add("Orange");
		
		colors.remove(2);
		Iterator iterator = colors.iterator();
		while(iterator.hasNext()) {
			String data = (String)iterator.next();
			System.out.println(data);
		}
	}
}
