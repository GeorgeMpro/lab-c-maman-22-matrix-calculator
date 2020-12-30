#include "input.h"

/*private functions*/
static int validateBeforeEndOfLIne(const char *, int);

static int doesEndWithComma(int, int);

static int checkCommaReset(char, int);

/*      ***Buffer setup and teardown***     */
/*Dynamically allocate memory to a buffer initialized to 0*/
char *initBuffer() {
    char *buffer;
    buffer = calloc(BUFFER_SIZE, sizeof(char));
    return buffer;
}

/*Clear buffer and allocate new memory*/
char *resetBuffer(char *buffer) {
    free(buffer);

    return initBuffer();
}
/*      ***Reading Input***     */
/*Get token from string*/
char *getToken(char *str, char *delimiter) {
    char *piece;
    piece = strtok(str, delimiter);
    return piece;
}

/*Check input for general sentence validity*/
int inputParamSeperators(char *buffer) {

    return validateInput(buffer);
}

/*Check valid dot and comma count before new line*/
int validateInput(char *buffer) {
    int commaCounter, isValid;
    commaCounter = 0;
    isValid = validateBeforeEndOfLIne(buffer, commaCounter);

    return isValid;
}

/*Read buffer by char*/
int validateBeforeEndOfLIne(const char *buffer, int commaCounter) {
    int i, dotCounter, isValid;
    char currentLetter;
    isValid = INVALID;
    for (i = 0; i <= strlen(buffer); ++i) {
        currentLetter = buffer[i];

        /*Reset commas on valid character*/
        commaCounter = checkCommaReset(currentLetter, commaCounter);

        if (IS_COMMA) {
            commaCounter++;
            dotCounter = 0;
        }

        if (commaCounter > 1) {
            printf(ERROR_COMMA);
            isValid = INVALID;
            break;
        }

        if (IS_DOT) {
            dotCounter++;
        }

        if (dotCounter > 1) {
            printf(ERROR_DOT);
            isValid = INVALID;
            break;
        }

        isValid = 0;
    }

    return doesEndWithComma(commaCounter, isValid);
}

/*Reset comma counter on valid input*/
int checkCommaReset(char c, int counter) {

    if (c != COMMA
        && c != ' '
        && c != '\n' /*New line*/
        && c != '\000'
        && c != 13 /*Carriage return*/
            ) {
        return 0;
    }

    /*Check if alphabet or letter*/
    if ((c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9')
            ) {
        return 0;
    }

    return counter;

}

/*Check valid input before new line*/
int doesEndWithComma(int commaCounter, int isValid) {
    if (commaCounter > 0) {
        printf(ERROR_END_WITH_COMMA);
        return INVALID;
    }
    return isValid;
}
