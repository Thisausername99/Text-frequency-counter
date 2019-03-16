#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "word.h" 
#include <errno.h> 


  int main(int argc, char * argv[], char * envp[]){
  	int n=0;
    char temp;
    char* error=(char*)malloc(sizeof(char));
    Node*head=NULL; //head node
    char *buffer=(char*)malloc(sizeof(char)); //buffer array
  	char make_to_word[20]; //array to store the word

    if(argc==1){
      char* file=getenv("WORD_FREAK");
      if(file==NULL){
          int check=-1;
          while((check=read(STDIN_FILENO,buffer,1))!=0){
            //write(STDOUT_FILENO,buffer,1);
            temp=*(buffer);
            make_to_word[n]=temp;
            ++n;
          if(!check_letter(temp)){ //indicate to make a word
            make_to_word[n-1]='\0';
            prependNode(&head,make_to_word,1,strlen(make_to_word)); //add to list  
            
            n=0;
            continue;
            }
          }
        }

      else{
          
          int fd=open(file,O_RDONLY);
          perror(error);
          if(fd==-1){//exit if file is not exit
            exit(EXIT_FAILURE);
          }
          else
          while(read(fd,buffer,1)!=0){
            temp=*(buffer);
            make_to_word[n]=temp;
            ++n;
          if(!check_letter(temp)){ //indicate to make a word
            make_to_word[n-1]='\0';
            prependNode(&head,make_to_word,1,strlen(make_to_word));
            
            n=0;
            continue;
            }
          }
          close(fd);
          perror(error);
          }
        }
  else{
  
  for(int a=1;argv[a]!=NULL;++a){
  int fd=open(argv[a],O_RDONLY);
  perror(error);
  int check=-1;
	while((check=read(fd,buffer,1))!=0){
    printf("%s",buffer);
    temp=*(buffer);
    make_to_word[n]=temp;
    ++n;
    if(!check_letter(temp)){ //indicate to make a word
      make_to_word[n-1]='\0';
      prependNode(&head,make_to_word,1,strlen(make_to_word));
      n=0;
    continue;
    }
  }
  close(fd);
  perror(error);
  }
}

print_freq(head);
free(buffer);
free_list(head);

return 0; 
}