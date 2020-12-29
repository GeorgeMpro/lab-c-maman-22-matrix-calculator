#include <string.h>
#include "mat.h"

/*  ****Setup and Teardown**** */
/*Initialize and name an array of matrices*/
void initMatrices(pmat matArray[]) {
    int i;
    for (i = 0; i < NUMBER_OF_MATRICES; ++i) {
        matArray[i] = iniMat();
        setGenericName(matArray, i);

        if (!matArray[i]) {
            printf("\nUnable to allocate memory to %d Matrices.\nClearing memory and exiting program.\n",
                   NUMBER_OF_MATRICES);
            exit(0);
        }
    }
}

/*Initialize matrix by allocating needed memory.*/
pmat iniMat() {
    pmat new;
    int i;
    new = calloc(1, sizeof(mat));
    if (new) {
        new->name = (char *) calloc(MAT_NAM_LENGTH, sizeof(char));
        new->data = (float **) calloc(ROW, sizeof(float *));
        if (new->name && new->data) {
            for (i = 0; i < COL; ++i) {
                new->data[i] = (float *) calloc(COL, sizeof(float));
            }
        }
    } else {
        free(new);
        printf("\nUnable to allocate memory.Exiting");
        exit(0);
    }

    return new;
}

/*Generate and set matrix name*/
char *setGenericName(pmat const *matArray, int i) {
    int n;
    char *prefix = "MAT_";
    char suf1 = 'A';
    char suf2;

    /*set and increment name according to given array index*/
    char *name = matArray[i]->name;
    strcpy(name, prefix);
    n = (int) suf1 + i;
    suf2 = (char) n;

    strncat(name, &suf2, 1);
    return name;
}

/*Clear allocated memory to matrix array*/
void clearAllocatedMatrices(pmat matArray[]) {
    int i;
    for (i = 0; i < NUMBER_OF_MATRICES; ++i) {
        freeMatrixMemory(matArray[i]);
    }
}

/*Clear allocated memory of given matrix*/
void freeMatrixMemory(mat *mat) {
    int j;
    float **data;

    free(mat->name);
    data = mat->data;
    for (j = 0; j < ROW; ++j) {
        free(data[j]);
    }
    free(data);
}

