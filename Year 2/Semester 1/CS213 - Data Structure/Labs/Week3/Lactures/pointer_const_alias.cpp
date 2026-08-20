#include <iostream>

using namespace std;

int main() {
  int n = 6;

  int *const nptr = &n; // *const ptr and alias are same effect, both of them
                        // can't change where the pointer point to.
  int &an = n;

  return 0;
}
