#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	for(int i = 0; i < 10; i++){
		void* a = calloc(2500000, sizeof(int));
		sleep(1);
	}
	return 0;
}
