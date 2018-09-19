#include <stdio.h>
#include <time.h>
#include <pthread.h>
#define TRUE 1
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#define TRUE 1

char buf[100];
int i = 0;
pthread_mutex_t mut;
pthread_cond_t condc;
pthread_cond_t condp;

int counter = 0; 

void *cons(void *ptr)
{
 while (TRUE) {
  pthread_mutex_lock(&mut);
  if (counter == 0){
    pthread_cond_wait(&condc, &mut);
  }
  buf[counter] = 'c';
  counter --;
  if (counter == 100 - 1){
   pthread_cond_signal(&condp);
   pthread_mutex_unlock(&mut);
  }
 }
}

time_t start_time;
void *prod(void *ptr)
{

 while (TRUE) { 
  pthread_mutex_lock(&mut);
  
  if (counter == 100){
   pthread_cond_wait(&condp, &mut);
  }
  buf[counter] = 'p';
  counter ++;
  time_t fin_time = time(NULL);
  double fraction = (double)(fin_time - start_time);

  if(fraction > i*60){
   printf("Time of execution:%f\n", ((double)(fin_time - start_time)));
   i++;
  }

  if (counter == 1){
   pthread_cond_signal(&condc);
   pthread_mutex_unlock(&mut);
  }
 }
}

int main(int argc, char const *argv[]){
 start_time = time(NULL);
 pthread_t pro, con;
 pthread_mutex_init(&mut, 0);
 pthread_cond_init(&condc, 0);
 pthread_cond_init(&condp, 0);
 pthread_create(&con, 0, cons, 0);
 pthread_create(&pro, 0, prod, 0);
 pthread_join(pro, 0);
 pthread_join(con, 0);
 pthread_cond_destroy(&condc);
 pthread_cond_destroy(&condp);
 pthread_mutex_destroy(&mut);
 
 return 0;

}