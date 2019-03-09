  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <unistd.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "struct.h"

  Node * new_node(char*word, int length, int freq);
  void add_to_front(Node* new, Node* head);

  
  void empty(char array[20]){
  	for (int n=0;n<=20;++n){
  		array[n]='\0';
  	}
  }




  int main(int argc, char * argv[]){

  	Node*head=NULL;
  	char *buffer=(char*)malloc(sizeof(char));
  	char make_to_word[20];
    if(argc==1){
      printf(" no argument \n");
      //int fd=open(STDIN_FILENO,O_RDONLY);
      while(read(STDIN_FILENO,buffer,1)!=0){
        write(STDOUT_FILENO,buffer,1);
        //if(strcmp(buffer,"\n")==0){
         // break;
       // }
    }
  }
  else{
  int fd=open(argv[1],O_RDONLY);
	int n=0;
	char temp;
	bool end =false;
	while (read(fd,buffer,1)!=0){
  	printf("%s",buffer);
    /*if(strcmp(buffer,",")!=0){                    //  strcmp(buffer," ")!=0 && strcmp(buffer,"\n ")!=0){
  	temp=*(buffer);
  	make_to_word[n]=temp;
  	make_to_word[n+1]='\0';
  	//printf(" append the word %s",make_to_word);
  	++n;
	}
	else

  	add_to_front(new_node(make_to_word,strlen(make_to_word),1),head);
  	//continue;
  	break;*/
  	}
  	
  	//make_to_word[n]='\0';
  	//printf("the word %s ",head->word);
	close(fd);
  }
  printf("wassup\n");
	return 0;  	
}