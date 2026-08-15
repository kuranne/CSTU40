package main;

import main.error.MyError.DividedByZeroException;

public class App {

    private static int divide(int a, int b) {
        if (b == 0) {
            throw new DividedByZeroException("Can't divided by zero");
        }
        return a / b;
    }

    public static void main(String[] args) {
        int x = 1;
        int y = 0;
        try {
            System.out.println(divide(x, y));
        } catch (RuntimeException e) {
            if (e instanceof DividedByZeroException) {
                System.err.printf("\033[1;31m%s\033[0m\n", e);
            }
        }
    }
}
