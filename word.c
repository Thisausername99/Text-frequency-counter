#include "word.h"
#include <stdio.h>
#include "struct.h"
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//extern int max_len;


char *copy_word (char *word) { //copy the word by value
  assert(word != NULL);
  int len = strlen(word);
  char *copy = (char *)(malloc(len+1));
  assert(copy != NULL);
  strcpy(copy, word);
  return copy;
}


bool check_letter(char c){ // check if it the letter
  if( (c>='a' && c<='z') || (c>='A' && c<='Z'))//check if char is letter or aphostrope
        return true;
    else
      return false;

}

int freq_len(int freq){
  if(freq == 0){
    return 0;
  }
  return 1 + freq_len(freq/10);
}


