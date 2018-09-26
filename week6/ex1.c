#include<stdio.h>
#include<unistd.h>
int main(){
	char s1[256];
	char s2[256];
	int buf[2];
	scanf("%s", s1);
	pipe(buf);
	write(buf[1], s1, 256);
	close(buf[1]);
	read(buf[0], s2, 256);
	close(buf[0]);
	printf("%s", s2);
	return 0;	
}	
