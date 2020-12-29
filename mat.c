#include <string.h>
#include "mat.h"


/*Initialize and name an array of matrices*/
void initMatrices(pmat matArray[]) {
    int i;

    for (i = 0; i < NUMBER_OF_MATRICES; ++i) {
        matArray[i] = iniMat();
        setGenericName(matArray, i);

        /*todo del*/
        printf("\nname %s\n", matArray[i]->name);

        if (!matArray[i]) {
            printf("\nUnable to allocate memory to %d Matrices.\nClearing memory and exiting program.\n",
                   NUMBER_OF_MATRICES);
            /*todo clear memory if error*/
            exit(0);
        }
    }

}

/*Initialize matrix by allocating needed memory.*/
pmat iniMat() {
    pmat new;
    int i, j;
    new = calloc(1, sizeof(mat));
    if (new) {
        new->name = (char *) calloc(MAT_NAM_LENGTH, sizeof(char));
        new->data = (float **) calloc(ROW, sizeof(float *));
        if (new->name && new->data) {
            for (i = 0; i < COL; ++i) {
                new->data[i] = (float *) calloc(COL, sizeof(float));
                /*todo check if cannot allocate memory and clear*/
            }
        }

    } else {
        free(new);
        return NULL;
    }

    return new;
}
/*todo cleanup*/
/*Generate and set matrix name*/
char *setGenericName(pmat const *matArray, int i) {
    int n;
    char *prefix = "MAT_";
    char suf1 = 'A';
    char suf2;

    char *name = matArray[i]->name;
    strcpy(name, prefix);
    n = (int) suf1 + i;
    suf2 = (char) n;

    strncat(name, &suf2, 1);
    return name;
}

/*Access specified cell in given matrix*/
float accessCell(pmat mat, int row, int col) {
    return mat->data[row][col];
}

/*todo alternative syntax to access cell*/
/*Change value in given matrix cell.*/
void modifyCell(pmat mat, int row, int col, float value) {
    *(*((mat->data) + row) + col) = value;
}

/*Print given matrix name and values*/
void print_mat(pmat mat) {
    int i, j;
    printf("\n%s\n", mat->name);
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            printf("%4.2f\t", accessCell(mat, i, j));
        }
        printf("\n");
    }
}
