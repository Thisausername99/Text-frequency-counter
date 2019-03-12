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


void addToFront(char * word,int len, int freq, Node * head);

Node * new_node(char*word, int length, int freq, Node* head);

bool contain(char* word, Node* head);

void format(char* word);

void print_freq(Node*head);


#endif
