#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#define MAX_LINE_LEN 60
#ifndef MAX_WORD_LEN
  #define MAX_WORD_LEN 20
#endif
 
struct Node{
  char word[MAX_WORD_LEN+2];
  struct Node* next;
};
struct Node* lineHead;

struct Node* findLastNode(struct Node* lineHead){
  struct Node* iterator = lineHead;
  while(iterator->next != NULL) iterator = iterator->next;
  return iterator;
}

void clear_line(void)
{
  for(struct Node* current = lineHead;current!=NULL;){
    if(current == lineHead){ current = current->next;continue;}
    struct Node* temp = current;
    current = current->next;
    free(temp);
  }
  lineHead = NULL;
}

void add_word(const char *word){
  if(strcmp(word,"\r")==0){
    return;
  }
  //printf
  struct Node* toAdd = malloc(sizeof(struct Node));
  toAdd->next = NULL;
  strcpy(toAdd->word,word);
  if(lineHead == NULL){
    lineHead = toAdd;
    return;
  }
  else{
    struct Node* current = findLastNode(lineHead);
    current->next = toAdd;
  }
}
 
int space_remaining(void)
{
  int line_len = 0;
  struct Node* iterator = lineHead;
  while(iterator!=NULL){
    line_len+=strlen(iterator->word);
    if(iterator->next !=NULL){
      line_len++; //to pretend there exists ' '
    }
    iterator = iterator->next;
  }
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  for(struct Node* iterator = lineHead;iterator!=NULL;){
    printf("%s",iterator->word);
    if(iterator->next!=NULL){
      printf(" ");
    }
    iterator = iterator->next;
  }
  printf("\n");
  return;
}
 
void flush_line(void){
  for(struct Node* iterator = lineHead;iterator!=NULL;iterator= iterator->next){
    printf("%s",iterator->word);
    if(iterator->next!=NULL){
      printf(" ");
    }
  }
  printf("\n");
}
