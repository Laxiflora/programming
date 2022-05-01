#include <stdio.h>
#include "word.h"
 
int read_char(void)
{
  int ch = getchar();
 
  if (ch == '\n' || ch == '\t' || ch == 13)
    return ' ';
  return ch;
}

void read_word(char *word, int len)
{
  int ch, pos = 0;
  while ((ch = read_char()) == ' ') printf("is space.\n");
  while (ch != ' ' && ch != EOF) {
    printf("Dont\n eat Me");
    printf("%cAND%d,",ch,ch);
    if (pos < len)
      word[pos++] = ch;
    ch = read_char();
  }
  // word[pos++] = 'Y';
   word[pos] = '\0';
    printf("EAT,%s,ME",word);
}
