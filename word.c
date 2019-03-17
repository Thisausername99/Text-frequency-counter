#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "word.h"




/**
  * @desc copy the word by value not reference
  * @param char * word - word to copy
*/
char * copy_word(char * word) { //copy the word
  assert(word != NULL); //word not null
  int len = strlen(word); //length of the word
  char * copy = (char * )(malloc(len + 1)); //allocates space for the word
  assert(copy != NULL); //copy not null
  strcpy(copy, word); //copy and word 
  return copy;
}




/**
  * @desc check if a letter is not alphabetic or apostrophe by ASCII
  * @param char c - character to check
*/
bool check_letter(char c) { //check if it the letter
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 39) //check if char is letter or apostrophe
    return true;
  else
    return false;
}




/**
  * @desc print out the errno correspond the to error
  * @param int error - the errno number
*/
bool print_error(int error){ //writes error message to file descriptor
  if(error==0){
     return false;
  }
  char* error_msg;  //string for error message
  sprintf(error_msg,"The error # is %i\n",error); //format error message
  write(STDERR_FILENO,error_msg,strlen(error_msg));  //writes to file descriptor
  exit(error); //exits
  return true;
}




/**
  * @desc get the length of a digits for format
  * @param int * freq - the frequency 
*/
int freq_len(int freq) { //number of digits in number
  if (freq == 0) {
    return 0;
  }
  return 1 + freq_len(freq / 10); //recurses and adds one
}

