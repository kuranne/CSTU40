#include <stdio.h>

int main() {
  int *a = NULL;
  *a = 1;
  printf("%p", a);
  return 0;
}
