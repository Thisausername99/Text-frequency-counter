#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include "struct.h"
#include "word.h" 

extern int errno;


int main(int argc, char * argv[], char * envp[]) {
  int n = 0; //counter for index of make_to_word
  char temp; //temporary character
  Node * head = NULL; //head node
  char * buffer = (char * ) malloc(sizeof(char)); //buffer array
  char make_to_word[100]; //array to store the word

if (argc > 1) {
    for (int a = 1; argv[a] != NULL; ++a) { //goes through each arguments
      int fd = open(argv[a], O_RDONLY); //opens file to be read
      print_error(errno); //writes any errors

      while (read(fd, buffer, 1) != 0) {
        temp = * (buffer); //temp points to buffer's character
        make_to_word[n] = temp; //makes word using temp chars
        ++n; //increment counter
        if (!check_letter(temp)) { //indicate to make a word
          make_to_word[n - 1] = '\0'; //sets last character to end of string character
          prependNode( &head, make_to_word, 1, strlen(make_to_word)); //adds word to list
          n = 0; //reset index counter
          continue;
        }
      }
      close(fd); //close file
      print_error(errno); //writes any errors
    }
  } 

else if (getenv("WORD_FREAK") != NULL) { //if environment variable used
    int fd = open(getenv("WORD_FREAK"), O_RDONLY); //opens file to be read
    print_error(errno); //writes any errors

    while (read(fd, buffer, 1) != 0) {
      temp = * (buffer); //temp points to buffer's character
      make_to_word[n] = temp; //makes word using temp chars
      ++n; //increment counter
      if (!check_letter(temp)) { //indicate to make a word
        make_to_word[n - 1] = '\0'; //sets last character to end of string character
        prependNode( & head, make_to_word, 1, strlen(make_to_word)); //adds word to list
        n = 0; //resets index counter
        continue;
      }
    }
    close(fd); //close file
    print_error(errno); //writes any errors
  } 

else{//read in standard input 
  while (read(STDIN_FILENO, buffer, 1) != 0) { //while not end of file
      temp = * (buffer); //temp points to buffer's character
      make_to_word[n] = temp; //makes word using temp chars
      ++n; //increment counter
      if (!check_letter(temp)) { //indicate to make a word
        make_to_word[n - 1] = '\0'; //sets last character to end of string character
        prependNode( &head, make_to_word, 1, strlen(make_to_word)); //adds word to list  
        n = 0; //resets index counter
        continue;
      }
    }
  } 

print_freq(head); //format every node and writes them
free(buffer); //frees buffer
free_list(head); //frees list of words
return 0;
}

