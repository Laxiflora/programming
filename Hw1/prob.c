#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv){
	char name[4096];
    if(argc!=3 && argc != 4){
        printf("no para.\n");
        printf("%d",argc);
        return 0;
    }
    char* toDelete = argv[1];
    char* toReplace = argv[2];
    int toDeleteLength = strlen(toDelete);
    int toReplaceLength = strlen(toReplace);
    char* newLine;
	while(fgets(name,4096,stdin) != NULL){
        int changed = 0;
        char* cutPoint = name;
        cutPoint = strstr(cutPoint,toDelete);
        if(cutPoint!=NULL){
            changed = 1;
            name[strlen(name)-strlen(cutPoint)] ='\0';
            strcat(name,toReplace);
            strcat(name," ");
            printf("%s",name); 
        }
        if(changed == 1){
            strcat(name,"\n");
        }
        printf("%s",name);
    }
	return 0;
}
