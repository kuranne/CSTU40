#include <iostream>

using namespace std;

int main() {
  int n = 5, m = 9;
  int &an = n;

  cout << n << an << m << endl;
  printf("addr: %p %p %p\n", &n, &an, &m);

  an = m;

  cout << n << an << m << endl;
  printf("addr: %p %p %p\n", &n, &an, &m);

  return 0;
}
