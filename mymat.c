#include "mat.h"

int main() {
    /*todo init matrices A-F*/
    /*todo change to matArray*/
    pmat mArr[NUMBER_OF_MATRICES];
    initMatrices(mArr);

    /*todo friendly user promt and explanation*/
    /*todo show commands*/
    /*TODO user interface and loop code*/

    /*todo del testing code*/


    /*todo del*/
    pmat A = mArr[0];
    setCell(A, 0, 0, 1.f);
    setCell(A, 0, 1, 2.f);
    setCell(A, 0, 2, 3.f);
    setCell(A, 0, 3, 4.f);
    setCell(A, 2, 0, 5.f);
    setCell(A, 1, 3, 6.f);
    setCell(A, 3, 1, 2.f);
    setCell(A, 3, 2, 2.f);
    setCell(A, 3, 3, 2.f);
    /*todo del*/

    pmat C = mArr[2];
    setCell(C, 0, 1, 7.f);
    setCell(C, 0, 2, 8.f);
    setCell(C, 1, 0, 9.f);
    setCell(C, 1, 2, 10.f);
    setCell(C, 0, 1, 11.f);
    setCell(C, 1, 0, 12.f);
    setCell(C, 2, 2, 13.f);
    setCell(C, 3, 0, 13.f);
    setCell(C, 3, 3, 1.f);
    setCell(C, 2, 3, 1.f);
    setCell(C, 1, 3, 1.f);



/*todo del functions*/
    pmat D = mArr[3];

    print_mat(A);

    trans_mat(A, A);
/*
    print_mat(C);
*/
/*    mul_mat(A, C, D);*//*

    add_mat(A, A, A);
    add_mat(A, C, D);

    *//*todo del*//*
    sub_mat(C, A, D);
    sub_mat(A, A, D);*/


    /*todo clear memory allocation*/
    /*  clearAllocatedMatrices(mArr);*/

    return 0;
}
