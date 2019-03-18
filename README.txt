https://youtu.be/Lfj752ss7cc
# project3
Text Frequency

Highlight:

-Using linkedlist to store the words and their frequency
-Add word to the front to make the checking more efficient
-Contain move the word to the front since it is more prevalence
-Use sprintf to format and align the output 
-Using write read open close only with no I/O library
-Print out every error when using system call with errno
-Have 2 header files for struct functions and word functions
-Able to read standard input and file parses thtough environment variable WORD_FREAK
-Apply double pointer for adding and contain check
-Free the list and its nodes after printing out the output


All the three methods I applied the some one of reading the input one byte at a time to read character by character and build a word through a char array. 
If we encounter a space or any punctuations while reading it will indicate the end of the word then we add it to the front of the linkedlist.

I have a print_error function in word that print out the error using sprintf after every call to write, open, read ,close and will exit if an error occur.


Functions:

struct.c
  new_node - creates new word node
  prependNode - adds a new word node to the list
  contain - checks if word is already contained in the list
  format - aligns the word and counter
  print_freq - format every node
  free_node - frees a node
  free_list - frees list
  
 word.c
  copy_word - copy the word
  check_letter - checks if character is in the alphabet or an apostrophe
  print_error - writes error message to the file descriptor
  freq_len - number of digits in a number
  
