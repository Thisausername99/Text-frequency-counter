#ifndef STRUCT_H
#define STRUCT_H


#include <stdio.h>
#include <stdbool.h>


struct  Node{
	char*word;
	int freq;
	struct Node * next;
};
typedef struct Node Node;


Node * new_node(char*word,int freq, Node* head);

bool contain(char* word, Node ** head);

void format(char* word,int freq);

void print_freq(Node*head);

void prependNode(Node **head, char *word, int freq, int len);

void free_node(Node*node);

void free_list(Node*head);

#endif
