#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *arr, int n);
int main(){
  int *arr, n;
  scanf("%d",&n);
  arr = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d",(arr + i));
  bubbleSort(arr, n);
  for (int i = 0; i < n; i++)
    printf("%d ",*(arr + i));
 
}
void bubbleSort(int *arr, int n){
   int temp;
   for (int i = 0; i < n-1; i++){
     for (int j = 0; j < (n-i-1); j++){
       if (*(arr + j) > *(arr + j + 1)){
        temp = *(arr + j);
        *(arr + j) = *(arr + j + 1);
        *(arr + j + 1) = temp;
       }
     }
   }
   

}
