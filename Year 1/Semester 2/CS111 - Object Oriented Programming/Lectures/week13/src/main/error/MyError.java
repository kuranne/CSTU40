package main.error;

public class MyError {

    public static class DividedByZeroException extends RuntimeException {

        public DividedByZeroException(String msg) {
            super(msg);
        }
    }
}
