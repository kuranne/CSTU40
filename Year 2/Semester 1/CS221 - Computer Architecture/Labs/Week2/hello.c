#include <stdio.h>
#ifdef __x86_64__
#define ARCH "x86_64"
#else
#define ARCH "aarch64"
#endif

int main() {
  printf("%s\n", ARCH);
  return 0;
}
