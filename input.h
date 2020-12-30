#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 100
#define PROMT "\n$"

/*Text manipulation*/
#define COMMA ','
#define DELIM_END ", \r\n"
#define DOT '.'

#define IS_COMMA currentLetter == COMMA
#define IS_DOT currentLetter == DOT

/*Error messages*/
#define ERROR_COMMA "\nERROR:Multiple consecutive commas \',\'."

#define ERROR_DOT "\nERROR:Multiple consecutive dots \'.\' ."

#define ERROR_END_WITH_COMMA "\nERROR:Command should not end with a comma \',\'."

#define INVALID -1

#define VALID 1

/*Functions*/
char *initBuffer();

char *resetBuffer(char *buffer);

char *getToken(char *str, char *delimiter);

int inputParamSeperators(char *buffer);

int validateInput(char *buffer);
