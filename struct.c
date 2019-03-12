#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <assert.h>
#include "word.h"

int max_len=0; // keep track for formatting

Node * new_node(char *add, int length, int freq, Node *head){
	Node* new_word=(Node*)malloc(sizeof(Node));
	new_word->word=add;
	new_word->length=length;
	new_word->freq=freq;
	new_word->next=head;
	return new_word;
}

void addToFront(char * word,int len, int freq, Node * head) {
    if(strcmp(" ",word)==0){
    	return;
    }
    else if(contain(word,head)){
    	return;
    }
    Node * newNode = malloc(sizeof(Node));
    newNode->word=copy_word(word);
    newNode->length=len;
    if(len>max_len){
    	max_len=len;
    }
    newNode->freq=freq;
    newNode->next = head->next;
    head->next = newNode;
}


bool contain(char* word, Node * head){
	while(head!=NULL){
		if(strcmp(head->word,word)==0){
		   head->freq=head->freq+1;
		   return true;
		}
		else
			head=head->next;	
		}
	return false;
}



void format(char*word){ //format to align
  int len=strlen(word);
  int max_len=10;
  char farray[max_len];
  //sprintf(num,"%i",22);
  for(int n=0;n<=max_len;++n){
  	farray[n]=*(word+n);
    if(n>=len && n<max_len){
    farray[n]='-';
		}
    else if(n==max_len){
    farray[n]='\n';
    }
  }
  write(STDOUT_FILENO,farray,strlen(farray));
}

void print_freq(Node*head){ //format everynode
head=head->next;
while(head!=NULL){
	printf("%s\n",head->word);
	format(head->word);
	head=head->next;
	}
}








