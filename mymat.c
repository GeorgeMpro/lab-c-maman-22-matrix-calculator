#include "mat.h"

int main() {
    /*todo init matrices A-F*/
    pmat matArray[NUMBER_OF_MATRICES];
/*    initMatrices(matArray);*/
    pmat A = iniMat();
    A->name = "MAT_A";


    /*todo del*/
    float a;
    int i, j;
    i = 3;
    j = 2;
    a = accessCell(A, i, j);
    printf("Cell %4.2f\n", a);

    modifyCell(A, i, j, 300.3f);
    a = accessCell(A, i, j);
    printf("Cell %4.2f\n", a);
    modifyCell(A, 1, 3, 1000.3f);
    /*todo del*/
    print_mat(A);


    /*todo del*/
    printf("\nName %s", A->name);

    /*todo clear memory allocation*/

    return 0;
}
