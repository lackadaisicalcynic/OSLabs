#include<stdio.h>
#include<stdlib.h>

int ageing(int k) {
  FILE *file = fopen("input.txt", "r");
  char buff[256];
  int count = 0;
  int miss = 0;
  int hit = 0;
  int a; 
  do{
    fscanf(file, "%d", &a);
    count++;
  }
  while (fgetc(file) != EOF);
   

  fclose(file);
  file = fopen("input.txt", "r");
  int page;
  int *age = calloc(k, sizeof(int));
  int *frame = calloc(k, sizeof(int));
  for (int i = 0; i < count; i++){
    fscanf(file, "%d", &page);
    int free = 0;
    int hitted = 0;
    for(int j = 0; j < k; j++){
      age[j] = age[j] >> 1;
      if (frame[j] == page && hitted != 1){
        age[j] += (1<<31);
        hit++;
        hitted = 1;
             
      }      
    }
    if (!hitted){
      for(int j = 0; j < k; j++){
        if (frame[j] == 0){
          frame[j] = page;
          age[j] = 1<<31;
          miss++;
          free = 1;
          break;
        }
      }
    }  
    if (!free && !hitted){
      int ind = 0;
      int min = age[0];
      for (int j = 1; j < k; j++){
        if (age[j] < min){
          min = age[j];
          ind = j;
        }
      }
      frame[ind] = page;
      age[ind] = 1<<31;
      miss++; 
    }
  }
  fclose(file);
  printf("hit/miss rate: %f\n", (double) hit/miss);
  return 0;
}
int main(){
  ageing(10);
  ageing(50);
  ageing(100);
}