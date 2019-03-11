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

 //Node * new_node(char*word, int length, int freq, Node* head);
 //void addToFront(char * word,int len, int freq, Node * head);

  
  void empty(char array[20]){
  	for (int n=0;n<=20;++n){
  		array[n]='\0';
  	}
  }

  bool check_letter(char c){ // check if it the letter
  if( (c>='a' && c<='z') || (c>='A' && c<='Z'))
        return true;
    else
        printf("%c is not an alphabet.",c);
      return false;

  }



  int main(int argc, char * argv[], char * envp[]){
  	Node*head=new_node("",0,0,NULL);
    char *buffer=(char*)malloc(sizeof(char));
  	char make_to_word[20];
    if(argc==1){
      if(getenv("WORD_FREAK")==NULL){
      while(read(STDIN_FILENO,buffer,1)!=0){
        write(STDOUT_FILENO,buffer,1);
          }
        }
      else{
      int fd=open(getenv("WORD_FREAK"),O_RDONLY);
      while(read(fd,buffer,1)!=0){
        write(2,buffer,1);
      }
    }
  }
  else{
  int fd=open(argv[1],O_RDONLY);
	int n=0;
	char temp;
	bool end =false;
	while(read(fd,buffer,1)!=0){
    temp=*(buffer);
    if(!check_letter(temp)){ //indicate to make a word
    make_to_word[n]='\0';
    addToFront(make_to_word,strlen(make_to_word),1,head); // add to linkedlist
    n=0;
    continue;
    }
    make_to_word[n]=temp;
    ++n;
    }
	
  

	if(close(fd)==0){
    printf("No error\n");
  }
  else
    printf("There error is %i",errno);
    exit(-1);
  }
  //printf("wassup\n");
	return 0;  	
}