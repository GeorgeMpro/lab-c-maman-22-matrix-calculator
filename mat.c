#include "mat.h"

/*  ****Matrix Functionality**** */
/*Access specified cell in given matrix*/
float getCell(pmat mat, int row, int col) {
    return mat->data[row][col];
}

/*Change value in given matrix cell.*/
void setCell(pmat mat, int row, int col, float value) {
    *(*((mat->data) + row) + col) = value;
}

/*Print given matrix name and values*/
void print_mat(pmat mat) {
    int i, j;
    printf("%s\n", mat->name);
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            printf("%7.2f\t", getCell(mat, i, j));
        }
        printf("\n");
    }
}

/*Sum two matrices and put values into third specified matrix*/
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
    printf("\nResult:");
    print_mat(sum);
}

/*Subtract two matrices and put values into third specified matrix*/
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
    printf("\nResult:");
    print_mat(sum);
}

/*Multiply given matrices*/
void mul_mat(pmat m1, pmat m2, pmat result) {
    int i, j, k;
    float tmpSum;
    tmpSum = 0;
    printf("\nMultiplying %s * %s = %s", m1->name, m2->name, result->name);
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

/*Multiply matrix by scalar*/
void mul_scalar(pmat m, const float *scalar, pmat result) {
    int i, j;
    float tmpSum;

    printf("\nMultiplying by scalar %4.2f * %s = %s", *scalar, m->name, result->name);
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            tmpSum = *scalar * getCell(m, i, j);
            setCell(result, i, j, tmpSum);
        }
    }
    printf("\nResult:");
    print_mat(result);
}

/*Transpose matrix to given matrix*/
void trans_mat(pmat from, pmat transposed) {
    int i, j;
    float tmpNum;
    pmat tmpMat;
    tmpMat = iniMat();

    printf("\nTransposing %s to %s", from->name, transposed->name);
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            tmpNum = getCell(from, i, j);
            setCell(tmpMat, j, i, tmpNum);
        }
    }

    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            tmpNum = getCell(tmpMat, i, j);
            setCell(transposed, i, j, tmpNum);
        }
    }

    freeMatrixMemory(tmpMat);

    printf("\nResult:");
    print_mat(transposed);
}

/*Copy matrix to copy*/
void read_mat(pmat destination, pmat copy, char *name) {
    int i, j;
    float tmpSum;
    destination->name = name;
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            tmpSum = getCell(copy, i, j);
            setCell(destination, i, j, tmpSum);
        }
    }
    printf("\nWritten ");
    print_mat(destination);
}
