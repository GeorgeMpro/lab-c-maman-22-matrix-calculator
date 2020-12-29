/*Libraries*/
#include <stdio.h>
#include <stdlib.h>


/*Definitions*/
#define ROW 4
#define COL 4
#define MAT_NAM_LENGTH 5
#define NUMBER_OF_MATRICES 6

typedef struct {
    char *name;
    float **data;
} mat;

typedef mat *pmat;

/*Function Definitions*/
void initMatrices(pmat matArray[]);

pmat iniMat();

float accessCell(pmat mat, int row, int col);

void modifyCell(pmat mat, int row, int col, float value);

void print_mat(pmat mat);

char *setGenericName(pmat const *matArray, int i);