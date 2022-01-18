#ifndef EXAMPLE
#define EXAMPLE

#include <stdio.h>

/**
 * Example structure. Provides an example of c-style structure definition and
 * creation.
 */
typedef struct example_struct {
  int a; /**< an integer field. */
  int b; /**< an integer field. */
} example_struct;
/**
 * Function to create an instance of example_struct.
 * @param a input integer to fill field a of the new example_struct.
 * @param b input integer to fill field b of the new example_struct.
 * @return a new instance of example_struct with contents a and b.
 */
example_struct createExampleStruct(int a, int b);

#endif // EXAMPLE