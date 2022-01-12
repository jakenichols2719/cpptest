#include "headers/cbp-struct-example.h"

#ifdef BUILD_MAIN
int main(int argc, char *argv[]) {
  example_struct x = createExampleStruct(0, 1);
  printf("Hello, World\n");
  printf("Created example struct x with (%d, %d)\n", x.a, x.b);
  return 0;
}
#endif