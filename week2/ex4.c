#include<stdio.h>
void swap(int*, int*);
int main(){
  int a,b;
  scanf("%d", &a);
  scanf("%d", &b);
  swap(&a, &b);
  printf("%d\n", a);
  printf("%d", b);
  return 0;
}
void swap(int *a, int *b){
 int t = *a;
 *a = *b;
 *b = t;
}