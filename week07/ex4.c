#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
void *myrealloc(void *ptr, size_t size){
	if(size == 0){
		free(ptr);
		return NULL;
	}
	if(ptr == NULL){
		return malloc(size);
	}
	else{
		void* copy = malloc(size);
		memcpy(copy, ptr, size);
		return copy;
	}
}
int main(){
	
	int *ptr = calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++) {
        	ptr[i] = 0;
    	}
	ptr = myrealloc(ptr, 5*sizeof(int));
	for (int i = 0; i < 5; i++) {
        	printf("%d ", ptr[i]);
    	}
	return 0;
}