#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void printWithCase(char* name,const char* toDelete,const char* toReplace){
    char output[4096] = {'\0'};
    int current=0;
    char* cutPoint;
    char* cutSub;
    if(strstr(name,toDelete)==NULL){ // no need to replace
        printf("%s", name);
        return;
    }
    else{
        while(strstr(name,toDelete)!=NULL){
            cutPoint = strstr(name,toDelete);
            current =strlen(name)-strlen(cutPoint);  //len to copy
            name[current] = '\0';
            strcat(output,name);
            strcat(output,toReplace);
            name = &name[current+strlen(toDelete)];
        }
        strcat(output,name);
        printf("%s",output);
    }

}

void printWithNoCase(char* name,const char* toDelete,const char* toReplace){
   char output[4096] = {'\0'};
    int current=0;
    char* cutPoint;
    char* cutSub;
    if(strcasestr(name,toDelete)==NULL){ // no need to replace
        printf("%s", name);
        return;
    }
    else{
        while(strcasestr(name,toDelete)!=NULL){
            cutPoint = strcasestr(name,toDelete);
            current =strlen(name)-strlen(cutPoint);  //len to copy
            name[current] = '\0';
            strcat(output,name);
            strcat(output,toReplace);
            name = &name[current+strlen(toDelete)];
        }
        strcat(output,name);
        printf("%s",output);
    }
}





int main(int argc,char **argv){
	char name[4096];
    int noCase = 0;
    if(argc!=3 && argc != 4){
        printf("The input format: string1 string2 [parameter]");
        return 0;
    }
    if(argc>3){
        if(strcmp(argv[3],"-i")==0){
            noCase=1;
        }
    }
    char* toDelete = argv[1];
    char* toReplace = argv[2];
    int toDeleteLength = strlen(toDelete);
    int toReplaceLength = strlen(toReplace);
    char* newLine;
	while(fgets(name,4096,stdin) != NULL){
        if(noCase==0){
            printWithCase(name,toDelete,toReplace);
        }
        else{
            printWithNoCase(name,toDelete,toReplace);
        }
    }
	return 0;
}


