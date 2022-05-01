#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NAME_LENGTH 64

struct course{
    struct course* next;
    struct course* piror;
    char course_name[NAME_LENGTH];
};


struct mapper{
    int course_id,next_id,piror_id;
    char course_name[NAME_LENGTH];
    struct course* link;
};

void makeList(struct course**,struct mapper*,int);






int main(int argc,char** argv){
    int n;
    struct course* root = NULL;
    scanf("%d",&n);
    struct mapper input[n];
    for(int i=0;i<n;i++){
        int course_id,next,piror;
        char* course_name;
        scanf("%d %d %d %s",&input[i].course_id,  &input[i].next_id,  &input[i].piror_id,  input[i].course_name);
        input[i].link = malloc(sizeof(struct course));
        strcpy(input[i].link->course_name,input[i].course_name);
    }
    makeList(&root,input,n);
    char option;
    struct course* current = root;

    do{
        printf("Current Course: %s\n",current->course_name);
        printf("[n] Next course. [p] Prior course [q] Quit:");
        scanf(" %c",&option);
        getchar();
        if(option == 'n'){
            if(current->next ==NULL){
                printf("There is no next course.\n");
                continue;
            }
            current = current->next;
        }
        if(option == 'p'){
            if(current->piror ==NULL){
                printf("There is no previous course.\n");
                continue;
            }
            current = current->piror;
        }
    }while(option != 'q');
    return 0;

}


struct course* findCourse(int keyid,struct mapper* input,int coursenum){//find course with given courseID
    for(int i=0;i<coursenum;i++){
        if(input[i].course_id == keyid){
            return input[i].link;
        }
    }
    return NULL;
}


void makeList(struct course** root,struct mapper* input,int coursenum){
    
    for(int i=0;i<coursenum;i++){  //for each course
        input[i].link->next = findCourse(input[i].next_id,input,coursenum);
        input[i].link->piror = findCourse(input[i].piror_id,input,coursenum);
    }
    *root = input[0].link;
    for(int i=0;i<coursenum;i++){
        input[i].link = NULL;
    }
    
}

