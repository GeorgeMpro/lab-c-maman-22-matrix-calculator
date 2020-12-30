/*Libraries*/
#include "command_util.h"



/*Main program*/
int main() {
    /*Variables*/
    pmat mArr[NUMBER_OF_MATRICES];
    char *buffer;
    usrCommands cmd[] = {
            {ADD_TEXT,    add_mat},
            {SUD_TEXT,    sub_mat},
            {MUL_TEXT,    mul_mat},
            {SCALAR_TEXT, (void (*)()) mul_scalar},
            {TRANS_TEXT,  trans_mat},
            {READ_TEXT,},
            {PRINT_TEXT,  print_mat},
            {STOP_TEXT,}
    };

    /*program initialization*/
    initMatrices(mArr);
    buffer = initBuffer();

    /*Program*/
    /*User instructions*/
    printf("\nWelcome to Maman 14 Matrix calculator.");
    printf("\nCommands should be lower case followed by a space.");
    printf("\nAvailable commands: stop, print_mat,read_mat, add_mat,sub_mat,mul_mat,mul_scalar,trans_mat.");
    printf("\nMatrices should be upper case. Available MAT_A to MAT_F.");
    printf("\nParameters should be separated by a \',\' comma except for the last one.");
    printf(PROMT);
    buffer = runProgram(buffer, cmd, mArr);

    /*Memory clearance*/
    printf("\nClearing memory...");
    clearAllocatedMatrices(mArr);
    free(buffer);
    printf("\nGoodbye!\n");

    return 0;
}
