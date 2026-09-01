#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  char hello1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
  char hello2[] = "Hello";

  /* Notice that both two of string declared is objtype and can do as char*
   * it also class so can use like str.length() that give result like
   * strlen(str)
   */
  string hello3("Hello");
  string hello4 = "Hello";

  // --- To strcmp
  char hello12 = strcmp(hello1, hello2);

  // or use hello3.append(hello4) also give the same result.
  string hello34 = hello3 + hello4;

  cout << hello12 << hello34 << endl;

  return 0;
}
