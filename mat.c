#include "mat.h"

void initMatrices(pmat matArray[]) {
    int i;
    for (i = 0; i < NUMBER_OF_MATRICES; ++i) {
        matArray[i] = iniMat();
        if (!matArray[i]) {
            printf("\nUnable to allocate memory to %d Matrices.\nClearing memory and exiting program.\n",
                   NUMBER_OF_MATRICES);
            /*todo clear memory if error*/
            exit(0);
        }
    }

}

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

float accessCell(pmat mat, int row, int col) {
    return mat->data[row][col];
}

/*todo alternative syntax to access cell*/
void modifyCell(pmat mat, int row, int col, float value) {
    *(*((mat->data) + row) + col) = value;
}


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
