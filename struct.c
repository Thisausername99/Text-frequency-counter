#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <assert.h>
#include "word.h"

int max_len = 0; //keep track for formatting

Node * new_node(char * add, int freq, Node * nextNode) { //creates new word node
  Node * new_word = (Node * ) malloc(sizeof(Node)); //allocates space for the node
  new_word->word = copy_word(add); //sets node's word to a copy of the currently read word
  new_word->freq = freq; //sets frequency of the word
  new_word->next = nextNode; //sets the next node in the list
  return new_word;
}

void prependNode(Node ** head, char * word, int freq, int len) { //adds a new word node to the list
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

bool contain(char * word, Node ** head) { //checks if word is already contained in the list
  Node * curr = * head, * prev = NULL; //initialize current and previous pointers
  while (curr != NULL) { //loop until the end of the list
    if (strcmp(curr->word, word) == 0 && prev != NULL) { //word is in the list
      prev->next = curr->next; //takes word out of list
      curr->freq = curr->freq + 1; //increases word frequency
      curr->next = * head; //puts word at the beginning of the list
      * head = curr; //head pointer is now to curr
      return true;
    } else
      prev = curr; //previous is current node
      curr = curr->next; //current is the next
  }
  return false;
}

void format(char * word, int freq) { //aligns the word and counter
  int len = strlen(word); //length of the current word
  char farray[max_len + freq_len(freq) + 50]; //set size for the buffer
  sprintf(farray, "%s %*s %2i\n", word, max_len - len + 1, ":", freq); //formats the line in the array
  strcat(farray, "\0"); //concats the end of string character to the end of the string
  write(STDOUT_FILENO, farray, strlen(farray)); //writes to the file descriptor
}

void print_freq(Node * head) { //format every node
  while (head != NULL) { //loop until the end of the list
    format(head->word, head->freq); //aligns the word and counter
    head = head->next; //go to next node
  }
}

void free_node(Node * node) { //frees a node
  if (node != NULL) { //not null
    free(node->word); //frees word
    free(node); //frees node
  }
  return;
}

void free_list(Node * head) { //frees list
  if (head != NULL) { //not null
    free_list(head->next); //recurses to the end of the list
    free_node(head); //frees node
    return;
  }
}
