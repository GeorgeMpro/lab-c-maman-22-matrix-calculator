#include "mat.h"

/*  ****Matrix Functionality**** */
/*Access specified cell in given matrix*/
float getCell(pmat mat, int row, int col) {
    return mat->data[row][col];
}

/*todo alternative syntax to access cell*/
/*Change value in given matrix cell.*/
void setCell(pmat mat, int row, int col, float value) {
    *(*((mat->data) + row) + col) = value;
}

/*Print given matrix name and values*/
void print_mat(pmat mat) {
    int i, j;
    printf("\n%s\n", mat->name);
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            printf("%4.2f\t", getCell(mat, i, j));
        }
        printf("\n");
    }
}

/*todo write and clean*/
/*Sum two matrices and put values to third specified matrix*/
void add_mat(pmat m1, pmat m2, pmat sum) {
    int i, j;
    float tmpSum;
    printf("\nAdding %s + %s = %s", m1->name, m2->name, sum->name);
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            tmpSum = getCell(m1, i, j) + getCell(m2, i, j);
            setCell(sum, i, j, tmpSum);
        }
    }
    /*todo del?*/
    printf("\nResult:");
    print_mat(sum);
}

void sub_mat(pmat m1, pmat m2, pmat sum) {
    int i, j;
    float tmpSum;
    printf("\nSubtracting %s - %s = %s", m1->name, m2->name, sum->name);
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            tmpSum = getCell(m1, i, j) - getCell(m2, i, j);
            setCell(sum, i, j, tmpSum);
        }
    }
    /*todo del?*/
    printf("\nResult:");
    print_mat(sum);
}

/*Multiply given matrices*/
void mul_mat(pmat m1, pmat m2, pmat result) {
    int i, j, k;
    float tmpSum;
    tmpSum = 0;
    printf("\nMultiplying %s X %s = %s", m1->name, m2->name, result->name);
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            tmpSum = 0;
            for (k = 0; k < COL; ++k) {
                tmpSum += getCell(m1, i, k) * getCell(m2, k, j);
            }
            setCell(result, i, j, tmpSum);
        }
    }
    print_mat(result);
}
