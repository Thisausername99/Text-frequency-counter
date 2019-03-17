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

extern int errno;

bool print_error(int error){
      if(error==0){
        return false;
      }
      char* error_msg;
      sprintf(error_msg,"The error # is %i\n",error);
      write(STDERR_FILENO,error_msg,strlen(error_msg));
      exit(error);
      return true;
}



int main(int argc, char * argv[], char * envp[]){
  int n=0;
  char temp;
  Node*head=NULL; //head node
  char *buffer=(char*)malloc(sizeof(char)); //buffer array
  char make_to_word[100]; //array to store the word

  if(argc>1){
    for(int a=1;argv[a]!=NULL;++a){
      int fd=open(argv[a],O_RDONLY);
      print_error(errno);
      
    while(read(fd,buffer,1)!=0){
    //printf("%s",buffer);
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
      print_error(errno);
    }
  }

  else if(getenv("WORD_FREAK")!=NULL){
      int fd=open(getenv("WORD_FREAK"),O_RDONLY);
      print_error(errno);
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
      print_error(errno);
  }

  else if(!isatty(STDIN_FILENO)){
       while(read(STDIN_FILENO,buffer,1)!=0){// && !isatty(STDIN_FILENO)){
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
    exit(-1);
  }
  
print_freq(head);
free(buffer);
free_list(head);

return 0; 
}