#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char delim[256]={'\0'};
int delim_current = 0;

void searchForDelim(char* name){
    for(int i=0;i<strlen(name);i++){
        if(!isalnum(name[i])){
            delim[delim_current++] = name[i];
            if(name[i] == '-'){    //cancel the operation
                delim[--delim_current] = '\0';
            }
        }
    }
    delim[delim_current++] = '\t';
    delim[delim_current++] = '\r';

}


/*
Caution:
_strcasestr didn't simulate as a original strcasestr, since it's output is incorrect.
But the length of the string is same, thus is ok to use in this program.
*/
int _strcasestr(char* input , const char* compare){
    char lowCase_input[4096];
    char lowCase_compare[4096];
    strcpy(lowCase_input,input);
    for(int i=0;i<strlen(compare);i++){
        lowCase_compare[i] = tolower(compare[i]);
    }
    for(int i=0;i<strlen(input);i++){
        lowCase_input[i] = tolower(input[i]);
    }
    if(strstr(lowCase_input,lowCase_compare) == NULL){
        return -1;
    }
    return strlen(strstr(lowCase_input,lowCase_compare));
}


void replaceCaseString(char* name , const char* toDelete , const char* toReplace){
    char output[4096] = {'\0'};
    char* cutPoint = strstr(name,toDelete);
    int current =strlen(name)-strlen(cutPoint);  //len to copy
    name[current] = '\0';
    strcat(output,name);
    strcat(output,toReplace);
    name = &name[current+strlen(toDelete)];
    strcat(output,name);
    printf("%s\n",output);
}

void replaceString(char* name , const char* toDelete , const char* toReplace){
    char output[4096] = {'\0'};
    int cutPoint = _strcasestr(name,toDelete);
    int current =strlen(name)-cutPoint;  //len to copy
    name[current] = '\0';
    strcat(output,name);
    strcat(output,toReplace);
    name = &name[current+strlen(toDelete)];
    strcat(output,name);
    printf("%s\n",output);
}


void printWithCase(char* name,const char* toDelete,const char* toReplace){
    char* word;
    word = strtok(name,delim);
    if(strstr(word,toDelete)!=NULL){
        replaceCaseString(word,toDelete,toReplace);
    }

    while((word = strtok(NULL,delim)) != NULL){
        if(strstr(word,toDelete) != NULL){
            replaceCaseString(word,toDelete,toReplace);
        }
    }
}

void printWithNoCase(char* name,const char* toDelete,const char* toReplace){  //不管大小寫
    char* word;
    word = strtok(name,delim);
    _strcasestr(word,toDelete);
    if(_strcasestr(word,toDelete)!=-1){
        replaceString(word,toDelete,toReplace);
    }

    while((word = strtok(NULL,delim)) != NULL){
           // printf("word = %s\n",word);
        if(_strcasestr(word,toDelete) != -1){
            replaceString(word,toDelete,toReplace);
        }
    }
}

int main(int argc,char **argv){
	char name[4096];
    int noCase = 0;
    char pre[4096];
   // printf("Enter pattern, replacement, and at most one parameter: ");
    fgets(pre,4096,stdin);

    // extract args
    char* temp;
    char  _argv[5][256];
    temp = strtok(pre," ");
    int _argc=1;
    if(strcmp(temp," ")!=0){
        strcpy(_argv[_argc++],temp);
    }
    while((temp = strtok(NULL," "))!=NULL){
        if(strcmp(temp," ")!=0){
            strcpy(_argv[_argc++],temp);
            if(_argc == 4){   //there must be -i
                if(strcmp(_argv[3],"-i\n")==0 || strcmp(_argv[3],"-i")==0){
                    noCase=1;
                }
                else{
                    printf("The input format: string1 string2 [parameter]");
                    return 0;
                }
            }
        }
        if(_argc>4 && strcmp(temp,"\n")!=0){
            printf("The input format: string1 string2 [parameter]");
            return 0;
        }
    }
    if(_argc<3){
        printf("The input format: string1 string2 [parameter]");
        return 0;
    }
    _argv[_argc-1][strlen(_argv[_argc-1])-1] = '\0';
    //
    // if(argc!=3 && argc != 4){
    //     printf("The input format: string1 string2 [parameter]");
    //     return 0;
    // }
    // if(argc>3){
    //     if(strcmp(argv[3],"-i")==0){
    //         noCase=1;
    //     }
    //     else{
    //         printf("The input format: string1 string2 [parameter]");
    //         return 0;            
    //     }
    // }
    // char* toDelete = argv[1];
    // char* toReplace = argv[2];
	while(fgets(name,4096,stdin) != NULL){
        if (name[0] == '\n'){
            continue;
        }
        name[strlen(name)-1]='\0';
        searchForDelim(name);
        if(noCase==0){
            printWithCase(name,_argv[1],_argv[2]);
        }
        else{
            printWithNoCase(name,_argv[1],_argv[2]);
        }
    }
	return 0;
}



