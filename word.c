#include "word.h"
#include <stdio.h>
#include "struct.h"
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>


char * copy_word(char * word) { //copy the word
  assert(word != NULL); //word not null
  int len = strlen(word); //length of the word
  char * copy = (char * )(malloc(len + 1)); //allocates space for the word
  assert(copy != NULL); //copy not null
  strcpy(copy, word); //copy and word 
  return copy;
}

bool check_letter(char c) { //check if it the letter
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 39) //check if char is letter or apostrophe
    return true;
  else
    return false;

}

int freq_len(int freq) { //number of digits in number
  if (freq == 0) {
    return 0;
  }
  return 1 + freq_len(freq / 10); //recurses and adds one
}
