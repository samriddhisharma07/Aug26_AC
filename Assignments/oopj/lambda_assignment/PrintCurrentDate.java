package lambda_assignment;
import java.time.LocalDate;
import java.util.function.Supplier;
public class PrintCurrentDate {
    public static void main(String[] args) {
        Supplier<LocalDate> date = () -> LocalDate.now();
        System.out.println(date.get());
    }
}
