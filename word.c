#include "word.h"
#include <stdio.h>
#include "struct.h"
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

extern int max_len;


char *copy_word (char *word) {
  assert(word != NULL);
  int len = strlen(word);
  char *copy = (char *)(malloc(len+1));
  assert(copy != NULL);
  strcpy(copy, word);
  return copy;
}


bool check_letter(char c){ // check if it the letter
  if( (c>='a' && c<='z') || (c>='A' && c<='Z') || c==39 || c=='-')
        return true;
    else
        //printf("%c is not an alphabet.",c);
      return false;

}



