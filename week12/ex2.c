#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  FILE** files = malloc(argc * sizeof(FILE*));
  if (strcmp(argv[1],"-a") == 0){
    for (int i = 2; i < argc; i++){
        files[i] = fopen(argv[i],"a"); 
    }
  }
  else{
    for (int i = 1; i < argc; i++){
      files[i] = fopen(argv[i], "w");
    }
  }
  char buffer[256];
  ssize_t res = read(0, buffer, 256);
  files[0] = fopen("/dev/stdout", "w");
  fprintf(files[0], "%s", buffer);
  if (strcmp(argv[1],"-a") == 0){
    for (int i = 2; i < argc; i++){
        fprintf(files[i], "%s", buffer);
        fclose(files[i]);
    }
  } 
  else{
      for (int i = 1; i < argc; i++){
        fprintf(files[i], "%s", buffer);
        fclose(files[i]);
    }
  } 
  return 0;
}