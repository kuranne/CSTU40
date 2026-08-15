class Test {
    private:
        float b;
        Test(int a, float b) {
            storedValue(a, b);
        }

    public:
        int a;
        // Constructure of Test class
        Test() {}
        // Overloading Constructure of Test class
        // Save Behavior with in Java
        Test(int a) {
            this->a = a;
            this->b = 1.0F;
        }
};

int main() {
    return 0;
}