#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv){
	char name[4097];
    if(argc!=3 && argc != 4){
        printf("no para.\n");
        printf("%d",argc);
        return 0;
    }
    char* toDelete = argv[1];
    char* toReplace = argv[2];
    char* cutPoint;
    char* newLine;
	while(fgets(name,4096,stdin) != NULL){
        printf("%s",name);
        cutPoint = strstr(name,toDelete);
        if(cutPoint!=NULL){
            char* head;
            memcpy(cutPoint,toReplace,strlen(toReplace));
        }
        printf("%s",name);
    }
	return 0;
}
