#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  fgets(str, 100, stdin);
  int n = strlen(str);
  for (int i = n; i >= 0; i--){
    putchar(str[i]);
  }
  return 0;

}