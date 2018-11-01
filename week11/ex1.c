#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(void) {
    char* s = "This is a nice day";
    int file = open("ex1.txt", O_RDWR, 0); 
    struct stat st;
    fstat(file, &st); 
    char* buff = (char*)mmap(NULL, st.st_size, PROT_WRITE, MAP_SHARED, file, 0); 
    memcpy(buff, s, strlen(s));
    for (int i = strlen(s); i < st.st_size; i++){
        buff[i] = ' ';
    }
    munmap(buff, st.st_size);
   

    close(file);
}