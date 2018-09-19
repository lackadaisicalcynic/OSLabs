#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thread(void *a){
	int *t_number = (int *) a;
	printf("Thread number: %d\n aaaaaaaaa\n", *t_number);	
}
int main(){
	int n;
	scanf("%d", &n);
	pthread_t id[n];
	for (int i = 0; i < n; i++){
		pthread_create(&id[i], NULL, thread, (void *)&id[i]);
	}
	for (int i = 0; i < n; i++){
		pthread_join(id[i], NULL);
	}
	pthread_t id1;
	for (int i = 0; i < n; i++){
		pthread_create(&id1, NULL, thread, (void *)&id1);
		pthread_join(id1, NULL);
	}
	pthread_exit(NULL);
	return 0;	
	
			


}	
