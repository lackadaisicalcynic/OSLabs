#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main(){
    pid_t id = fork();
    if(id == 0) {
        while(1){
            printf("I'm alive\n");
            sleep(1);
        }
        exit(EXIT_SUCCESS);	
    }
    else{
        sleep(10);
        kill(id, SIGTERM);
	exit(EXIT_SUCCESS);
    }
		
    return 0;
}