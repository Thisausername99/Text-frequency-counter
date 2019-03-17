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

bool print_error(int error) { //writes error message to file descriptor
  if (error == 0) { //no error
    return false;
  }
  char * error_msg; //string for error message
  sprintf(error_msg, "The error # is %i\n", error); //format error message
  write(STDERR_FILENO, error_msg, strlen(error_msg)); //writes to file descriptor
  exit(error); //exits
  return true;
}

int main(int argc, char * argv[], char * envp[]) {
  int n = 0; //counter for index of make_to_word
  char temp; //temporary character
  Node * head = NULL; //head node
  char * buffer = (char * ) malloc(sizeof(char)); //buffer array
  char make_to_word[100]; //array to store the word

  if (argc > 1) {
    for (int a = 1; argv[a] != NULL; ++a) { //goes through each file
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
  else if (!isatty(STDIN_FILENO)) {
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
  else {
    exit(-1);
  }
  print_freq(head); //format every node and writes them
  free(buffer); //frees buffer
  free_list(head); //frees list of words
  return 0;
}
