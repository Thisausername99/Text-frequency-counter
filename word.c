#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "word.h"
#include <stdio.h>



char *copy_word (char *word) {
  assert(word != NULL);
  int len = strlen(word);
  char *copy = (char *)(malloc(len+1));
  assert(copy != NULL);
  strcpy(copy, word);
  return copy;
}


bool check_letter(char c){ // check if it the letter
  if( (c>='a' && c<='z') || (c>='A' && c<='Z'))
        return true;
    else
        printf("%c is not an alphabet.",c);
      return false;

  }


