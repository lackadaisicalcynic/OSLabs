#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/resource.h>
int main(){
	struct rusage usage;
	for(int i = 0; i < 10; i++){
		void* a = calloc(2500000, sizeof(int));
		getrusage( RUSAGE_SELF, &usage);
		printf("Maximum resident set size: %ld\n", usage.ru_maxrss);
		printf("Page reclaims: %ld\n", usage.ru_minflt);
		printf("Page faults: %ld\n", usage.ru_majflt);
		printf("Swaps: %ld\n\n", usage.ru_nswap);
		sleep(1);
	 }
	return 0;
}
