#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	char s1[256];
	scanf("%s", s1);
	char s2[256];
	int buf[2];
	pipe(buf);
	pid_t pid = fork();
	if (pid != 0){
		write(buf[1], s1, 256);		
		close(buf[1]);
		close(buf[0]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	else{
		read(buf[0], s2, 256);
		printf("%s", s2);
		close(buf[0]);
		close(buf[1]);
		exit(EXIT_SUCCESS);
		
			
	}
	return 0;
}	
