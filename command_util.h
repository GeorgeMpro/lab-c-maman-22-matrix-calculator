#include "input.h"
#include "mat.h"

/*  ***Definitions***   */
#define INPUT_COMMAND "\nEntered Command: %s"

/*  **Lookup Table Specifications** */
/*Look up number*/
#define ADD_MAT 1

#define SUB_MAT 2

#define MUL_MAT 3

#define MUL_SCALAR 4

#define TRANS_MAT 5

#define STOP 6

#define PRINT_MAT 7

#define READ_MAT 8

#define MAT_USE_NUM_ARGS 3

/*Command name*/
#define ADD_TEXT "add_mat"

#define SUD_TEXT "sub_mat"

#define MUL_TEXT "mul_mat"

#define SCALAR_TEXT "mul_scalar"

#define TRANS_TEXT "trans_mat"

#define STOP_TEXT "stop"

#define READ_TEXT "read_mat"

#define PRINT_TEXT "print_mat"

/*Error messages*/
#define ERROR_INVALID_MATRICES "\nERROR: Invalid matrices."

#define ERROR_TOO_MANY_PARAMS "\nERROR: Too many arguments for command %s"

#define ERROR_UNDEFINED_COMMAND "\nERROR:Undefined command: %s\n"

/*The maximum number of paramters that can be carried*/
#define MAX_PARAMS ROW * COL + 1

/*Structures*/
typedef struct {
    char *key;
    int val;
} table;

typedef struct {
    char *name;

    void (*func)();
} usrCommands;

typedef struct {
    char *name;

    table ta;

    void (*func)();

    /*max amount of parameters is read_mat and matrix dimensions*/
    char *param[MAX_PARAMS];
} commandToExecute;

/*          ***Function Declarations***            */
char *runProgram(char *, usrCommands *, pmat *);

void extractParams(pmat *, char *, commandToExecute);

void chooseCommand(pmat *, commandToExecute, int);

void runThreeMats(commandToExecute *, pmat *);

pmat getMatrix(char *, pmat *);

void setupCommandTableLookup(commandToExecute *);

void printFromCommand(commandToExecute *, pmat *);

void transFromCommand(commandToExecute *, pmat *);

void threeMatrixExecution(pmat *, commandToExecute *, int);

void printFromInputCommand(pmat *, commandToExecute *, int);

void verifyMulScalar(pmat *, commandToExecute *comToEx, int);

void verifyTranspose(pmat *, commandToExecute *, int);

void mulFromCommand(commandToExecute *, pmat *);

void readMatrixSetup(pmat *, commandToExecute *, int);

float *extractNumFromParam(char *s);

void verifyReadMat(pmat *matrices, commandToExecute *cmd, int params);

