package java_ArrayList;

import java.util.ArrayList;
import java.util.Iterator;

public class Retrieve {
	public static void main(String[] args) {
		ArrayList <String> colors = new ArrayList<String>();
		colors.add("Blue");
		colors.add("Red");
		colors.add("Orange");
		System.out.println(colors.get(0));
		String data = colors.get(1);
		System.out.println(data);
	}
}
