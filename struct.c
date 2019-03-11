#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <assert.h>



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
    newNode->freq=freq;
    newNode->next = head->next;
    head->next = newNode;
}


char *copy_word (char *word) {
  assert(word != NULL);
  int len = strlen(word);
  char *copy = (char *)(malloc(len+1));
  assert(copy != NULL);
  strcpy(copy, word);
  return copy;
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

void printlist(Node*head){  
	while(head!=NULL){
		printf("the word is %s, it freq %i \n",head->word,head->freq);
		head=head->next;
	}

}







/*void initialize_map(Map * map[], int size){
	for(int n=0;n<size;++n){
		map[n]=(Map*)malloc(sizeof(Map));
	}

}

Key * new_word(char* new, int freq){
	Key * word=(Key*)malloc(sizeof(Key));
	word->word=new;
	word->freq=freq;
	return word;
}

void add_to_list(Map * map[], Key * key){
	static int n=0;
	if(contain(map,key->word)){
		return;
	}
	if(n<=100){
		map[n]->key=key;
		++n;
	}
	else{

	Map**temp_map=map;
	initialize_map(map,n*2);
	for (int a=0;a<n;++n){
		map[n]=temp_map[n];
	}
	map[n]->key=key;
	free (temp_map);
	}
}


bool contain (Map *map[] , char * search){
	int n=0;
	while(map[n]->key!=NULL){
		if(strcmp(map[n]->key->word,search)==0){return true;}
		++n;
	}
	return false;
}

void print_freq(Map *map[]){
	int count=0;
	while(map[count]->key!=NULL){
	
	printf("%s : %i\n",map[count]->key->word,map[count]->key->freq);	
	++count;
	}
}*/
