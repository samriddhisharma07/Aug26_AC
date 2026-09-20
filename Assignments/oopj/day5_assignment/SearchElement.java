package java_ArrayList;

import java.util.ArrayList;
import java.util.Iterator;

public class SearchElement {
	public static void main(String[] args) {
		ArrayList <String> colors = new ArrayList<String>();
		colors.add("Blue");
		colors.add("Red");
		colors.add("Orange");
		boolean result = colors.contains("Blue");
		if(result) {
			int value = colors.indexOf("Blue");
			String data = colors.get(value);
			System.out.println(data);
		}else {
			System.out.println("Data not present");
		}
	}
}
