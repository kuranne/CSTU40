#include <iostream>

using namespace std;

class Test {
    private:
        string txt;
};

int main() {
    Test obj1;
    Test *pobj1 = &obj1;
    Test obj3;
    Test *pobj3 = &obj3;

    Test *pobj2 = new Test();
    cout << pobj1 << endl << pobj3 << endl << pobj2 << endl;
    return 0;
}