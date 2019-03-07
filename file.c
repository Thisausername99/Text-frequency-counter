#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "file.h"
#include <stdio.h>

extern int errno;

void read_file(char *path , char * buffer){
	int fd=open(path, O_RDWR, S_IRUSR | S_IWUSR);
	if(fd!=-1){
	ssize_t num_read=read(fd,buffer,sizeof(fd));
	if(num_read==0){
		close(fd);
		return;
	}
	else
		printf("There an error\n");
	}	
	else
	printf("The error is %i",errno); 
}

