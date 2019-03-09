#ifndef STRUCT_H
#define STRUCT_H


#include <stdio.h>
#include <stdbool.h>


struct  Node{
	char*word;
	int length;
	int freq;
	struct Node * next;
};
typedef struct Node Node;

char *copy_word (char *word);

void addToFront(char * word,int len, int freq, Node * head);

Node * new_node(char*word, int length, int freq, Node* head);

bool contain(char* word, Node* head);

void printlist(Node*head);

/*struct Map{
	Key * key;
};
typedef struct Map Map;


void intialize_map(Map *map[],int size);

Key * new_word(char* new, int freq);

void add_to_list(Map * map[],Key * key);

bool contain(Map * map[], char * search);

int get_hash(Key* key); 

void print_freq(Map *map[]);*/

#endif
