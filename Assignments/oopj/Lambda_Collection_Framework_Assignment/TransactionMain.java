package examPractice;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Scanner;
class Transaction {
    int txId;
    LocalDate txDate;
    float txAmount;
    boolean txStatus;
    boolean txArrears;

    Transaction(int id, LocalDate date, float amount, boolean status, boolean arrears) {
        txId = id;
        txDate = date;
        txAmount = amount;
        txStatus = status;
        txArrears = arrears;
    }

    public String toString() {
        return txId + " " + txDate + " " + txAmount + " " + txStatus + " " + txArrears;
    }
}
public class TransactionMain {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Transaction> list = new ArrayList<Transaction>();

        for(int i = 0; i < 5; i++) {

            System.out.println("Enter Transaction Details");

            System.out.print("Enter ID: ");
            int id = sc.nextInt();

            System.out.print("Enter Date: ");
            LocalDate date = LocalDate.parse(sc.next());

            System.out.print("Enter Amount: ");
            float amount = sc.nextFloat();

            System.out.print("Enter Status: ");
            boolean status = sc.nextBoolean();

            System.out.print("Enter Arrears: ");
            boolean arrears = sc.nextBoolean();

            Transaction t = new Transaction(id, date, amount, status, arrears);
            list.add(t);
        }

        System.out.println("Transactions having amount > 5000");

        list.stream()
            .filter(t -> t.txAmount > 5000)
            .forEach(t -> System.out.println(t));

        System.out.println("Transactions having status false");

        list.stream()
            .filter(t -> t.txStatus == false)
            .forEach(t -> System.out.println(t));

        System.out.println("Amount Due");

        list.forEach(t -> {
            float due;

            if(t.txArrears == true) {
                due = t.txAmount + 500 + (18 * t.txAmount / 100);
            } else {
                due = t.txAmount;
            }

            System.out.println("Transaction ID: " + t.txId);
            System.out.println("Amount Due: " + due);
        });
    }
}
