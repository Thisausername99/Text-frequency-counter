#include <stdio.h>
#include "struct.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "file.h"



int main(int argc, char* argv[]){	
	void initialize_map(Map *map[],int size);
	char*buffer;
	char*file;
	if(argc==0){
		printf("Type the directory of file:\n");
		scanf("%s",file);
	read_file(file,buffer);
	}
	
	else{
	for(int n=1; argv[n]!=NULL;++n){
		printf("Succeed");



	
	/*Map * map[100];
	initialize_map(map,100);
	Key * test=new_word("Hey",1);
	Key * test2=new_word("Im Pretty",1);
	add_to_list(map,test);
	add_to_list(map,test2);
	print_freq(map);*/

	}
}
	return 0;
	

}
