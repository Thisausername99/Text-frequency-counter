#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <assert.h>
#include "word.h"

int max_len=0; // keep track for formatting

Node * new_node(char *add, int freq, Node *nextNode){
	Node* new_word=(Node*)malloc(sizeof(Node));
	new_word->word=copy_word(add);
	new_word->freq=freq;
	new_word->next=nextNode;
	return new_word;
}


void prependNode(Node **head, char *word, int freq, int len){
    if(contain(word,head) || strcmp("",word)==0){
      return;
    }
    else{
    Node * newNode = new_node(word,freq,NULL);
    if(len>max_len){
      max_len=len;
    }
    newNode->next = *head;
    *head = newNode;
  }
}


bool contain(char* word, Node ** head){
  Node *curr=*head,*prev=NULL;
  while(curr!=NULL){
		if(strcmp(curr->word,word)==0 && prev!=NULL){
      prev->next=curr->next;
      curr->freq=curr->freq+1;
      curr->next=*head;
      *head=curr;
	  return true;
  }
    else
    prev=curr;
    curr=curr->next;  
}
	return false;
}


void format(char*word,int freq){ //format to align
  int len=strlen(word);
  char farray[max_len+freq_len(freq)+50]; //set size for the buffer
  sprintf(farray,"%s %*s %2i\n",word,max_len-len+1,":",freq);
  strcat(farray,"\0"); // use to format
  write(STDOUT_FILENO,farray,strlen(farray));
}


void print_freq(Node*head){ //format everynode
while(head!=NULL){
	format(head->word,head->freq);
	head=head->next;
	}
}

  
void free_node(Node*node){
    if(node!=NULL){
      free(node->word);
      free(node);
    }
    return;
}


void free_list(Node*head){
 if(head!=NULL){
    free_list(head->next);
    free_node(head);
    return;
  } 
}





