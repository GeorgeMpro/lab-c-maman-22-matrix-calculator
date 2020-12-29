
#include "mat.h"


/*  ****Matrix Functionality**** */
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


