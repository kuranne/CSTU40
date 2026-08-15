public class TupleTest {
    private record Tuple(int x, String y) {}
    
    public static void main(String[] args) {
        Test test = new Test();
        int x = test.getStringandInt().x;
        String y = test.getStringandInt().y;
        
        System.out.printf("x: %d, y: %s", x, y);
    }

    public TupleTest() {}
    

    public static class Test {
        int x;
        String y;
        public Test() {
            x = 1;
            y = "Hello";
        }

        public Tuple getStringandInt() {
            return new Tuple(x, y);
        }
    }
}