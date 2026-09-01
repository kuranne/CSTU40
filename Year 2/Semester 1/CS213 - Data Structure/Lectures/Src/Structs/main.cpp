#include "Student.h"
#include <iostream>

using namespace std;

int main() {
  Student s1, *s2; // Already is in memory, else if Student *stu <-- it just a
                   // pointer so no in memory
  s1.name = "Jane Doe\n";
  s1.id = "0001";

  s2->name = "John Smith\n";
  s2->id = "0002";

  cout << s1.name << s2->name << endl;

  return 0;
}
