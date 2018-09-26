#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_kill()
{
  
    printf("received SIGKILL\n");
    exit(1);	

}
void sig_stop(){
    printf("received SIGSTOP\n");
    exit(1);
}
void sig_usr(){
        printf("\nSIGUSR1\n");
        kill(getpid(), SIGUSR1);
}
void sig_int(){
        printf("\nSIGINT\n");
            exit(1);
}

int main(void)
{
  signal(SIGINT, sig_int);
  signal(SIGKILL, sig_kill);
  signal(SIGSTOP, sig_stop);
  signal(SIGUSR1, sig_usr);
  while(1) 
    sleep(1);
  return 0;
}