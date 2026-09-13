package java_work;

public class ComplexNumber {
    int number1;
    int number2;
    public int getNumber1() {
        return number1;
    }
    public void setNumber1(int number1) {
        this.number1 = number1;
    }

    public int getNumber2() {
        return number2;
    }
    public void setNumber2(int number2) {
        this.number2 = number2;
    }
    int computeComplexNumber() {
        return number1 * number2;
    }
    public static void main(String[] args) {
        ComplexNumber[] arr = new ComplexNumber[5];
        for(int tmp = 0; tmp < 5; tmp++) {
            arr[tmp] = new ComplexNumber();
            arr[tmp].setNumber1(tmp + 1);
            arr[tmp].setNumber2(tmp + 2);
        }
        for(int tmp = 0; tmp < 5; tmp++) {
            System.out.println(arr[tmp].computeComplexNumber());
        }
    }
}
