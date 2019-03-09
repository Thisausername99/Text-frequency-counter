  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <unistd.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "struct.h"
  #include <errno.h>

 

  extern int errno;

 Node * new_node(char*word, int length, int freq, Node* head);
 void addToFront(char * word,int len, int freq, Node * head);

  
  void empty(char array[20]){
  	for (int n=0;n<=20;++n){
  		array[n]='\0';
  	}
  }




  int main(int argc, char * argv[]){

  	Node*head=new_node("",0,0,NULL);

  	char *buffer=(char*)malloc(sizeof(char));
  	char make_to_word[20];
    if(argc==1){
      printf(" no argument \n");
      //int fd=open(STDIN_FILENO,O_RDONLY);
      while(read(STDIN_FILENO,buffer,1)!=0){
        write(STDOUT_FILENO,buffer,1);
        //if(strcmp())
    }
  }
  else{
  int fd=open(argv[1],O_RDONLY);
	int n=0;
	char temp;
	bool end =false;
	while (read(fd,buffer,1)!=0){
    write(2,buffer,1);
    temp=*(buffer);
    make_to_word[n]=temp;
    ++n;
    //printf("after %s \n",make_to_word);

    if(strcmp(buffer,",")==0){
    make_to_word[n-1]='\0';
    addToFront(make_to_word,strlen(make_to_word),1,head);
    printf("append the word %s\n",make_to_word);
    //empty(make_to_word);
    n=0;
    continue; 
    
    //++n;
	 }
	}


  printlist(head);
	if(close(fd)==0){
    printf("No error\n");
  }
  else
    printf("There error is %i",errno);
    exit(-1);
  
  }
  printf("wassup\n");
	return 0;  	
}