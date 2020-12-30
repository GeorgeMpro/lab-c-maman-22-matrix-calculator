#include "command_util.h"

/*Lookup Table for identifying commands and using switch cases*/
table lookUpTable[] = {
        {ADD_TEXT,    ADD_MAT},
        {SUD_TEXT,    SUB_MAT},
        {MUL_TEXT,    MUL_MAT},
        {SCALAR_TEXT, MUL_SCALAR},
        {TRANS_TEXT,  TRANS_MAT},
        {PRINT_TEXT,  PRINT_MAT},
        {READ_TEXT,   READ_MAT},
};

/*The main program loop*/
char *runProgram(char *buffer, usrCommands *cmd, pmat *arr) {
    char *piece;
    int i, commandExists, isValidInput, isValidStop;
    commandToExecute execute;
    isValidStop = INVALID;
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        printf(INPUT_COMMAND, buffer);

        /*check basic validity before reading the logic of the piece*/
        isValidInput = inputParamSeperators(buffer);
        if (isValidInput != INVALID) {
            /*Set to non-existing command initially*/
            commandExists = INVALID;

            char extra[BUFFER_SIZE];
            strcpy(extra, buffer);

            piece = getToken(buffer, " \n\r");
            /*Deal with empty lines*/
            if (piece != NULL) {
                for (i = 0; cmd[i].name != NULL; ++i) {

                    if (strcmp(cmd[i].name, piece) == 0) {
                        /*setup command name and function*/
                        execute.name = cmd[i].name;
                        execute.func = cmd[i].func;
                        extractParams(arr, piece, execute);

                        /*Special command to exit properly*/
                        if (strcmp(execute.name, STOP_TEXT) == 0) {
                            /*Validate stop command not extra*/
                            piece = strtok(extra, "\r");

                            if (strcmp(execute.name, piece) == 0) {
                                printf("\nShutting down...");
                                isValidStop = VALID;
                                goto STOP_PROGRAM;
                            }
                        }
                        commandExists = VALID;
                        break;
                    }
                }
            } else {
                /*NOTE:No error notification on empty string*/
                commandExists = VALID;
            }

            if (commandExists != VALID) {
                printf(ERROR_UNDEFINED_COMMAND, piece);
            }

            /*Clear allocated memory*/
            buffer = resetBuffer(buffer);

            /*User prompt*/
            printf(PROMT);
        }
    }
    STOP_PROGRAM:

    if (isValidStop != VALID) {
        printf("\nERROR:Forced program stop. To exit use the stop command.");
    }

    return buffer;
}

/*Extract parameters from input command*/
void extractParams(pmat *arr, char *piece, commandToExecute execute) {
    /*set table values for switch*/
    int j, paramIndex;
    paramIndex = 0;
    setupCommandTableLookup(&execute);
    /*Limit maximum number of parameters to be extracted*/
    for (j = 0; (piece != NULL && j <= MAX_PARAMS); ++j) {

        if (piece != NULL) {
            /*continue from previous index*/
            execute.param[paramIndex] = piece;
            paramIndex = j;
        }
        piece = getToken(NULL, DELIM_END);
    }
    chooseCommand(arr, execute, paramIndex);
}

/*Enable command to be found using lookup table*/
void setupCommandTableLookup(commandToExecute *execute) {
    int i;
    for (i = 0; lookUpTable[i].key != NULL; ++i) {
        if (strcmp(execute->name, lookUpTable[i].key) == 0) {
            execute->ta.key = lookUpTable[i].key;
            execute->ta.val = lookUpTable[i].val;
        }
    }
}

/*Build command from user input*/
void chooseCommand(pmat *matrices, commandToExecute comToEx, int numberOfParams) {
    /*Switch cases for command execution*/
    switch (comToEx.ta.val) {
        case PRINT_MAT:
            printFromInputCommand(matrices, &comToEx, numberOfParams);
            break;
            /*Multiple commands with the same execution*/
        case ADD_MAT:
        case SUB_MAT:
        case MUL_MAT:
            threeMatrixExecution(matrices, &comToEx, numberOfParams);
            break;
        case MUL_SCALAR:
            verifyMulScalar(matrices, &comToEx, numberOfParams);
            break;
        case TRANS_MAT:
            verifyTranspose(matrices, &comToEx, numberOfParams);
            break;
        case READ_MAT:
            verifyReadMat(matrices, &comToEx, numberOfParams);
            break;
    }
}

/*Verify before multiply by scalar execution*/
void verifyMulScalar(pmat *matrices, commandToExecute *comToEx, int numberOfParams) {
    if (numberOfParams == MAT_USE_NUM_ARGS) {
        mulFromCommand(comToEx, matrices);
    } else {
        printf(ERROR_TOO_MANY_PARAMS, (*comToEx).name);
    }
}

/*Verify before multiply matrices.*/
void mulFromCommand(commandToExecute *cmd, pmat *matrices) {
    pmat A;
    pmat B;
    float *ptr;

    A = getMatrix(cmd->param[0], matrices);
    ptr = extractNumFromParam(cmd->param[1]);
    B = getMatrix(cmd->param[2], matrices);
    if (A != NULL && B != NULL && ptr != NULL) {
        cmd->func(A, ptr, B);
    } else {
        printf("\nERROR:Invalid parameters for multiplication by scalar.");
    }
}

/*Verify before matrix transpose execution*/
void verifyTranspose(pmat *matrices, commandToExecute *comToEx, int numberOfParams) {
    if (numberOfParams == 2) {
        transFromCommand(comToEx, matrices);
    } else {
        printf("\nERROR:command %s should contain 2 matrices.", (*comToEx).name);
    }
}

/*Verify before reading matrix*/
void verifyReadMat(pmat *matrices, commandToExecute *cmd, int params) {
    if (params < 2) {
        printf("\nERROR:Too few arguments for %s. need at least 2.", cmd->name);
    } else {
        readMatrixSetup(matrices, cmd, params);
    }
}

/*Build matrix*/
void readMatrixSetup(pmat *matrices, commandToExecute *cmd, int param) {
    int i, row, col;
    pmat tmp;
    pmat write;
    float *tmpNum;
    write = iniMat();

    tmp = getMatrix(cmd->param[0], matrices);
    if (tmp != NULL) {

        /*Set temporary matrix*/
        for (i = 1, row = col = 0; i < param; i++, col++) {
            tmpNum = extractNumFromParam(cmd->param[i]);
            if (tmpNum != NULL) {
                if (col == COL) {
                    col = 0;
                    row++;
                }
                setCell(write, row, col, *tmpNum);
            } else {
                printf("\nERROR:Invalid number format: %s", cmd->param[i]);
                /*On invalid parameter end early and clear allocated memory*/
                goto INVALID_PARAMS;
            }
        }

        /*On valid parameters copy to specified existing matrix*/
        read_mat(tmp, write, tmp->name);
    } else {
        printf(ERROR_INVALID_MATRICES);
    }

    INVALID_PARAMS:
    freeMatrixMemory(write);
}

/*Verify before print execution*/
void printFromInputCommand(pmat *matrices, commandToExecute *comToEx, int numberOfParams) {
    if (numberOfParams == 1) {
        printFromCommand(comToEx, matrices);
    } else {
        printf("\nERROR:Command %s should contain a single matrix parameter.", (*comToEx).name);
    }
}

/*Extract valid float*/
float *extractNumFromParam(char *s) {
    int i;
    char c;
    float *ptr = calloc(1, sizeof(float));
    /*Check valid number*/
    for (i = 0; i <= strlen(s); ++i) {
        c = s[i];
        /*Check if alphabet or letter*/
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return ptr = NULL;
        }
    }

    /*NOTE: str to float does not work with c90*/
    *ptr = (float) strtod(s, NULL);
    return ptr;
}

/*Verify before execution of commands requiring three matrices*/
void threeMatrixExecution(pmat *matrices, commandToExecute *comToEx, int numberOfParams) {
    if (numberOfParams == MAT_USE_NUM_ARGS) {
        runThreeMats(comToEx, matrices);
    } else {
        printf(ERROR_TOO_MANY_PARAMS, (*comToEx).name);
    }
}

/*Transpose valid matrices*/
void transFromCommand(commandToExecute *cmd, pmat *matrices) {
    pmat A;
    pmat B;
    A = getMatrix(cmd->param[0], matrices);
    B = getMatrix(cmd->param[1], matrices);
    if (A != NULL && B != NULL) {
        cmd->func(A, B);
    } else {
        printf(ERROR_INVALID_MATRICES);
    }
}

/*Print valid matrices*/
void printFromCommand(commandToExecute *command, pmat *matrices) {
    pmat tmp;
    tmp = getMatrix(command->param[0], matrices);
    if (tmp != NULL) {
        command->func(tmp);
    } else {
        printf(ERROR_INVALID_MATRICES);
    }
}

/*Run commands involving three valid matrices*/
void runThreeMats(commandToExecute *cmd, pmat *matrices) {
    int paramIndex;
    pmat A;
    pmat B;
    pmat C;
    paramIndex = 0;
    A = getMatrix(cmd->param[paramIndex++], matrices);
    B = getMatrix(cmd->param[paramIndex++], matrices);
    C = getMatrix(cmd->param[paramIndex], matrices);

    if (A != NULL && B != NULL && C != NULL) {
        cmd->func(A, B, C);
    } else {
        printf(ERROR_INVALID_MATRICES);
    }
}

/*Return and existing matrix or NULL*/
pmat getMatrix(char *givenName, pmat *matrices) {
    int i;
    for (i = 0; i < NUMBER_OF_MATRICES; i++) {
        if (strcmp(givenName, matrices[i]->name) == 0) {
            return matrices[i];
        }
    }
    return NULL;
}

