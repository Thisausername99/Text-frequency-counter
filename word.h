#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>



#ifndef WORD_H
#define WORD_H

char *copy_word (char *word);
bool check_letter(char c);


#endif