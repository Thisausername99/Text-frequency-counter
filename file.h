#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef FILE_H
#define FILE_H

int errno;
//int open (const char* Path, int flags, int mode ); 
//int close(int fd); 
void read_file(char *path , char * buffer);

#endif