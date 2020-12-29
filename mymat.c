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
    setCell(mArr[0], 0, 0, 300.3f);
    setCell(mArr[0], 0, 1, 300.3f);
    setCell(mArr[0], 0, 2, 300.3f);
    setCell(mArr[0], 0, 3, 300.3f);
    setCell(mArr[0], 2, 0, 300.3f);
    setCell(mArr[0], 1, 3, 1000.3f);
    /*todo del*/
    print_mat(mArr[0]);

    setCell(mArr[2], 0, 1, 100.0f);
    setCell(mArr[2], 0, 2, 100.0f);
    setCell(mArr[2], 1, 0, 50.0f);
    setCell(mArr[2], 1, 2, 110.0f);
    setCell(mArr[2], 0, 1, 50.0f);
    setCell(mArr[2], 1, 0, 100.f);
    setCell(mArr[2], 2, 2, 22.f);
    setCell(mArr[2], 3, 0, 30.f);
    print_mat(mArr[2]);

    add_mat(mArr[0], mArr[2], mArr[3]);
    add_mat(mArr[0], mArr[0], mArr[0]);



    /*todo clear memory allocation*/
    clearAllocatedMatrices(mArr);

    return 0;
}
