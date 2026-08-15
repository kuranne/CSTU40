import func.io.FastReader;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;

public class Factorial {
    private static final FastReader in = new FastReader(System.in);
    private static final PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out), true);
    public static void main(String[] args) {
        long n = in.nextLong();
        out.println(factorial(n));
    }

    public static long factorial(long n) {
        if (n >= 1) {
            return n * factorial(n - 1);
        } else {
            return 1;
        }
    }
}