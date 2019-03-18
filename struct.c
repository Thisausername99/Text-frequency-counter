#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <assert.h>
#include "word.h"
#include "struct.h"


extern int errno; //to print out error 
int max_len=0; // keep track for formatting


/**
  * @desc allocate new memory for Node
  * @param char* add -word attribute
  * @param int freq  -freq attribute
  * @param Node*next_node - next Node
*/
Node * new_node(char * add, int freq, Node * next_node) { //creates new word node
  Node * new_word = (Node * ) malloc(sizeof(Node)); //allocates space for the node
  new_word->word = copy_word(add); //sets node's word to a copy of the currently read word
  new_word->freq = freq; //sets frequency of the word
  new_word->next = next_node; //sets the next node in the list
  return new_word;
}


/**
  * @desc add node to the front of List
  * @param Node **head - double pointer to head
  * @param char * word - word attribute 
  * @param int freq - freq attribute
  * @param int len - length to of the word to update max_len
*/
void prepend_node(Node ** head, char * word, int freq, int len) { //adds a new word node to the list
  if (contain(word, head) || strcmp("", word) == 0) { //don't add anything if the word is already in the list
    return;
  } else {
    Node * newNode = new_node(word, freq, NULL); //new node created
    if (len > max_len) { //that word's length is greater than the current max length
      max_len = len; //max length is now the new word's length
    }
    newNode->next = * head; //new node added to the front
    * head = newNode; //head is now the new node
  }
}


/**
  * @desc check if a word is contain and move to front
  * @param char* word - word to check
  * @param Node ** head - double pointer to head
*/
bool contain(char * word, Node ** head) { //checks if word is already contained in the list
  Node * curr = * head, * prev = NULL; //initialize current and previous pointers
  while (curr != NULL) { //loop until the end of the list
    if (strcmp(curr->word, word) == 0 && prev != NULL) { //word is in the list
      prev->next = curr->next; //takes word out of list
      curr->freq = curr->freq + 1; //increases word frequency
      curr->next = * head; //puts word at the beginning of the list
      * head = curr; //head pointer is now to curr
      return true;
    } 
    else
      prev = curr; //previous is current node
      curr = curr->next; //current is the next
  }
  return false;
}


/**
  * @desc format the output on consle
  * @param char* word - word to format
  * @param int freq - frequency to format
*/
void format(char * word, int freq) { //aligns the word and counter
  int len = strlen(word); //length of the current word
  char farray[max_len + freq_len(freq) + 50]; //set size for the buffer
  sprintf(farray, "%s %*s %2i\n", word, max_len - len + 1, ":", freq); //formats the line in the array
  strcat(farray, "\0"); //concats the end of string character to the end of the string
  write(STDOUT_FILENO, farray, strlen(farray)); //writes to the file descriptor
  print_error(errno);// print out error if occur
}


/**
  * @desc print out frequency of of word in every Node
  * @param Node * head - pointer to head
*/
void print_freq(Node * head) { //format every node
  while (head != NULL) { //loop until the end of the list
    format(head->word, head->freq); //aligns the word and counter
    head = head->next; //go to next node
  }
}


/**
  * @desc free node and its attribute
  * @param Node * node - node to free
*/
void free_node(Node * node) { //frees a node
  if (node != NULL) { //not null
    free(node->word); //frees word
    free(node); //frees node
  }
  return;
}


/**
  * @desc free the entire list
  * @param Node * head - head of the list
*/
void free_list(Node * head) { //frees list
  if (head != NULL) { //not null
    free_list(head->next); //recurses to the end of the list
    free_node(head); //frees node
    return;
  }
}
