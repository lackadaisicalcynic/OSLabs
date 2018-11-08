#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int data = open("/dev/random", O_RDONLY);
  unsigned char buffer[20];
  ssize_t result = read(data, buffer, 20);
  FILE* out = fopen("ex1.txt", "w");
  fprintf(out, "%s\n", buffer);
  for (int i = 0; i < 20; i++){
    fprintf(out, "%u " , buffer[i]);
  }
  fclose(out);
  close(data);
  return 0;
}