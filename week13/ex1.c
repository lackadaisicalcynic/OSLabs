#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int main() {
   FILE* file = fopen("input_ok.txt", "r");
   char s[255];
   int e[100];
   int cnt = 0;
   fgets(s, 255, file);
    for (int i = 0; i < strlen(s); i++){
        int j = 0; 
        char s1[255];
        while(s[i+j] != ' ' && i+j < strlen(s)){
            s1[j] = s[i+j];
            j++;
        }
        e[cnt++] = atoi(s1);
        i = i + j;    
    }
    fgets(s, 255, file);
    fgets(s, 255, file);
    int a[100];
    cnt = 0;
    for (int i = 0; i < strlen(s); i++){
        int j = 0; 
        char s1[255];
        while(s[i+j] != ' ' && i+j < strlen(s)){
            s1[j] = s[i+j];
            j++;
        }
        a[cnt++] = atoi(s1);
        i = i + j;    
    }
    int c[100][100];
    fgets(s, 255, file);
    fgets(s, 255, file);
    int cnt1 = 0;
    while(strcmp(s,"\n") != 0){
        cnt = 0;
        for (int i = 0; i < strlen(s); i++){
            int j = 0; 
            char s1[255];
            while(s[i+j] != ' ' && i+j < strlen(s)){
                s1[j] = s[i+j];
                j++;
            }
            c[cnt1][cnt++] = atoi(s1);
            i = i + j;    
        }
        cnt1++;
        fgets(s, 255, file);
    } 
    int r[100][100];
    cnt1 = 0;
    while(fgets(s, 255, file) != NULL){
        cnt = 0;
        for (int i = 0; i < strlen(s); i++){
            int j = 0; 
            char s1[255];
            while(s[i+j] != ' ' && i+j < strlen(s)){
                s1[j] = s[i+j];
                j++;
            }
            r[cnt1][cnt++] = atoi(s1);
            i = i + j;    
        }
        cnt1++;        
    } 
    int enough;
    for (int k = 0; k < cnt1; k++){
        for (int i = 0; i < cnt1; i++){
            enough = 1;
            for (int j = 0; j < cnt; j++){
                if(a[j] < r[i][j])
                enough = 0;
            }
            if (enough){
                for(int m = 0; m < cnt; m++){
                    a[m] +=  c[i][m];
                    c[i][m] = 0;
                    r[i][m] = 0;
                }
            }
        }
    }
    int deadlocked = 0;
    for (int i = 0; i < cnt1; i++){
        for (int j = 0; j < cnt; j++){
            if (c[i][j] != 0){
                deadlocked++;
                break;
            }
        }
    }
    FILE* out1 = fopen("output_dl.txt", "w");
    FILE* out2 = fopen("output_ok.txt", "w");
    if (deadlocked == 0){
        fprintf(out2, "No deadlock");
    }
    else
        fprintf(out1, "Number of deadlocks: %d", deadlocked);
    fclose(file);
    fclose(out1);
    fclose(out2);
    return 0;    
}