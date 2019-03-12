#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <errno.h>
#include "word.h"  

 

  extern int errno;

 //Node * new_node(char*word, int length, int freq, Node* head);
 //void addToFront(char * word,int len, int freq, Node * head);

  
  void empty(char array[20]){
  	for (int n=0;n<=20;++n){
  		array[n]='\0';
  	}
  }



  int main(int argc, char * argv[], char * envp[]){
  	int n=0;
    char temp;
    Node*head=new_node("",0,0,NULL);
    char *buffer=(char*)malloc(sizeof(char));
  	char make_to_word[20];
    if(argc==1){
      char* file=getenv("WORD_FREAK");
      if(file==NULL){
      while(read(STDIN_FILENO,buffer,1)!=0){
        write(STDOUT_FILENO,buffer,1);
          }
        }
      else{
      int fd=open(file,O_RDONLY);
      while(read(fd,buffer,1)!=0){
        temp=*(buffer);
        make_to_word[n]=temp;
        ++n;
      if(!check_letter(temp)){ //indicate to make a word
        make_to_word[n-1]='\0';
        addToFront(make_to_word,strlen(make_to_word),1,head); // add to linkedlist
        n=0;
        continue;
    }
  }
  close(fd);
      }
  }
  else{
  for(int a=1;argv[a]!=NULL;++a){
  int fd=open(argv[a],O_RDONLY);
  int check=-1;
	while((check=read(fd,buffer,1))!=0){
    //printf("%s",buffer);
    temp=*(buffer);
    make_to_word[n]=temp;
    ++n;
    if(!check_letter(temp)){ //indicate to make a word
      make_to_word[n-1]='\0';
      addToFront(make_to_word,strlen(make_to_word),1,head); // add to linkedlist
      n=0;
    continue;
    }
  }
  close(fd);
  /*if(close(fd)==0){
    printf("No error\n");
  }
  else
    printf("There error is %i",errno);
    exit(-1);*/
  }
    print_freq(head);
}
return 0; 
}