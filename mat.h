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

/* **matrix functionality** */
float getCell(pmat mat, int row, int col);

void setCell(pmat mat, int row, int col, float value);

void print_mat(pmat mat);


/* Can use the same matrix multiple times*/
void add_mat(pmat m1, pmat m2, pmat sum);


/* **setup teardown** */
void initMatrices(pmat matArray[]);

pmat iniMat();

char *setGenericName(pmat const *matArray, int i);

void clearAllocatedMatrices(pmat matArray[]);

void freeMatrixMemory(mat *mat);