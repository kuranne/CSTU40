#include <iostream>

using namespace std;

class Test {
    private:
        int number;
    public:
        int public_number = 1;
        Test() { this->number = 0; }
        Test(int number) { this->number = number; }
        auto read_number() { return this->number; }
        void write_number(int number) { this->number = number; }
};

int main() {
    Test test;
    int tmp; cin >> tmp;

    test.write_number(tmp);
    cout << test.read_number() << endl;

    return 0;
}