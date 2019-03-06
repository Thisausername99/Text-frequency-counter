#include <stdio.h>
#include "struct.h"




int main(void){	
	void initialize_map(Map *map[],int size);
	Map * map[100];
	initialize_map(map,100);
	Key * test=new_word("Hey");
	add_to_list(map,test);
	print_freq(map);
	return 0;

}
