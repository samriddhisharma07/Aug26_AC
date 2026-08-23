class Seventh {

    public static void main(String[] args) {

        int num1 = 10;
        int num2 = 12;
        int num3 = 13;

        if (num1 > num2) {

            if (num1 > num3) {
                System.out.println("num1 is larger");
            }
            else {
                System.out.println("num3 is larger");
            }
        }
        else {

            if (num2 > num3) {
                System.out.println("num2 is larger");
            }
            else {
                System.out.println("num3 is larger");
            }
        }
    }
}