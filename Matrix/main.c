#include <stdio.h>
#include "matrix.h"

int main(){
    int rows = 4; 
    int cols = 2;
    matrix* m = matrixCreate(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrixSetValue(m, i, j, i+j);
        }
    }
    matrixPrint(m);
    printf("Value at [%d, %d] is %lf\n", 2, 3, matrixGetValue(m, 2, 3));

    matrix* mT = matrixTranspose(m);
    matrixPrint(mT);

    rows = 2; 
    cols = 6;
    matrix* m2 = matrixCreate(rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrixSetValue(m2, i, j, i+j);
        }
    }
    matrixPrint(m2);
    matrix* m3 = matrixMul(m, m2);
    matrixPrint(m3);

    matrix* m4 = matrixSubScalar(m3, 5);
    matrixPrint(m4);

    matrix* m5 = matrixAddScalar(m4, 2);
    matrixPrint(m5);

    matrix* m6 = matrixMulScalar(m5, 2);
    matrixPrint(m6);

    matrix* m7 = matrixSub(m6, m4);
    matrixPrint(m7);

    matrixDelete(m);
    matrixDelete(m2);
    matrixDelete(m3);
    matrixDelete(m4);
    matrixDelete(m5);
    matrixDelete(m6);
    matrixDelete(m7);

    m = matrixCreate(5, 5);

    double values[5][5] = {
        {0, 1, 1, 2, 3},
        {4, 2, 1, 7, 3},
        {2, 1, 2, 4, 7},
        {9, 1, 0, 7, 0},
        {1, 4, 7, 2, 2}
    };

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrixSetValue(m, i, j, values[i][j]);
        }
    }
    matrixPrint(m);

    printf("Determinant of matrix is %.2lf\n", matrixDetChio(m));
    matrixDelete(m);

}