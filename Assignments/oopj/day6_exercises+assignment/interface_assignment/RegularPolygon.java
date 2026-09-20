package java_newAssignment;
interface RegularPolygon {
	int getNumSides();
	double getSideLength();
	default double getPerimeter() {
		return getNumSides()*getSideLength();
	}
	default double getInteriorAngle() {
		int n = getNumSides();
		return(n-2)*Math.PI/n;
	}
	static int totalSides(RegularPolygon[] polygon) {
		int sum=0;
		for(RegularPolygon p : polygon) {
			sum = sum + p.getNumSides();
		}
		return sum;
	}
}
class EquilateralTriangle implements RegularPolygon{
	double sideLength;
	int numSides;
	EquilateralTriangle(double sideLength){
		this.sideLength = sideLength;
	}
	public int getNumSides() {
		return 3;
	}
	public double getSideLength() {
		return sideLength;
	}
}
class Square implements RegularPolygon{
	double sideLength;
	Square(double sideLength){
		this.sideLength = sideLength;
	}
	public int getNumSides() {
		return 4;
	}
	public double getSideLength() {
		return sideLength;
	}
}


