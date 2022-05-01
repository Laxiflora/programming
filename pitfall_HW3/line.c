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
static struct Node* lineHead;
char line[MAX_LINE_LEN+1];
int num_words = 0;
 //line will be replaced to a ptr


struct Node* findLastNode(struct Node* lineHead){
  struct Node* iterator = lineHead;
  while(iterator->next != NULL) iterator = iterator->next;
  return iterator;
}

void clear_line(void)
{
  for(struct Node* current = lineHead;current!=NULL;){
    if(current == lineHead) continue;
    struct Node* temp = current;
    current = current->next;
    free(temp);
  }
  lineHead = NULL;
}

void add_word(const char *word){
  if(strlen(word)==0){
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
// if (num_words > 0) {
//   line[line_len] = ' ';
//   line[line_len+1] = '\0';
//   line_len++;
// }
  // strcat(line, word);
  // line_len += strlen(word);
  // num_words++;
}
 
int space_remaining(void)
{
  int line_len = 0;
  struct Node* iterator = lineHead;
  while(iterator!=NULL){
    line_len+=strlen(iterator->word);
    //line_len--; //for every \0 exist in each word
    if(iterator->next !=NULL){
      line_len++; //to pretend there exists ' '
    }
    iterator = iterator->next;
  }
  printf("remain %d space\n",MAX_LINE_LEN-line_len);
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  for(struct Node* iterator = lineHead;iterator!=NULL;iterator= iterator->next){
    printf("%s",iterator->word);
    if(iterator->next!=NULL){
      printf(" ");
    }
  }
  printf("\n");





  // int extra_spaces, spaces_to_insert, i, j;
 
  // extra_spaces = MAX_LINE_LEN - line_len;
  // for (i = 0; i < line_len; i++) {
  //   if (line[i] != ' ')
  //     putchar(line[i]);
  //   else {
  //     spaces_to_insert = extra_spaces / (num_words - 1);
  //     for (j = 1; j <= spaces_to_insert + 1; j++)
  //       putchar(' ');
  //     extra_spaces -= spaces_to_insert;
  //     num_words--;
  //   }
  // }
  // putchar('\n');
}
 
void flush_line(void){
  printf("flush line\n");
  for(struct Node* iterator = lineHead;iterator!=NULL;iterator= iterator->next){
    printf("%s",iterator->word);
    if(iterator->next!=NULL){
      printf(" ");
    }
  }
  printf("\n");
  // if (line_len > 0)
  //   puts(line);
}
