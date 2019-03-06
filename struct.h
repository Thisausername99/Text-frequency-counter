#ifndef STRUCT_H
#define STRUCT_H


#include <stdio.h>
#include <stdbool.h>


struct Key{
	char*word;
	int freq;
};
typedef struct Key Key;


struct Map{
	Key * key;
};
typedef struct Map Map;


void intialize_map(Map *map[],int size);

Key * new_word(char* new);

void add_to_list(Map * map[],Key * key);

bool contain(Map * map[], char * search);

int get_hash(Key* key); 

void print_freq(Map *map[]);

#endif
