package java_newAssignment;

public class Polygon{
	public static void main(String[] args) {
		Square sq = new Square(5);
		System.out.println("Sides = " + sq.getNumSides());
		System.out.println("Length = " + sq.getSideLength());
		System.out.println("Perimeter = " + sq.getPerimeter());
		System.out.println("Interior Angle = " + sq.getInteriorAngle());
		EquilateralTriangle et = new EquilateralTriangle(1.23);
		System.out.println("Sides = " + et.getNumSides());
		System.out.println("Length = " + et.getSideLength());
		System.out.println("Perimeter = " + et.getPerimeter());
		System.out.println("Interior Angle = " + et.getInteriorAngle());
        RegularPolygon[] arr = {sq, et};
        System.out.println("Total Sides = " +
                RegularPolygon.totalSides(arr));
	}
	
}
