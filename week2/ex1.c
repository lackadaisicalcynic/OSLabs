#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  int a = INT_MAX;
  float b = FLT_MAX;
  double c = DBL_MAX;
 
  printf("The value %d\n",a);
  printf("Size of variable %ld\n", sizeof(a));
  printf("The value %lf\n", b);
  printf("Size of variable %ld\n", sizeof(b));
  printf("The value %lf\n", c);
  printf("Size of variable %ld\n", sizeof(c));
  return 0;

}