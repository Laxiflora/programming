#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char in [4075] =  "A Ch aB Ch AAA Ch jjjj";
    char* temp;
    temp = strtok(in,"Ch");
    while((temp = strtok(NULL,"Che")) != NULL){
    printf("t:%s\n",temp);
    printf("i:%s\n",in);
    }
}