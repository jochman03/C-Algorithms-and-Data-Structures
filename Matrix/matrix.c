#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

/*
    Static helper function for handling memory allocation failures,
    preventing incorrect program behavior.
*/
_Noreturn static void allocationFailure(){
    fprintf(stderr, "There is not enough memory available.\n");
    exit(EXIT_FAILURE);
}

double matrixGetValue(matrix* m, int i, int j){
    // Check if matrix exists (is not null)
    if(m == NULL){
        fprintf(stderr, "Matrix does not exist.\n");
        return -1;
    }
    // Check if index is positive
    if(i < 0 || j < 0){
        fprintf(stderr, "Index could not be negative.\n");
        return -1;
    }
    // Check if index matches the matrix dimensions
    if(i >= m->rows || j >= m->cols){
        fprintf(stderr, "Index out of bounds.\n");
        return -1;
    }
    // Return value of matrix element using the macro.
    return m->data[MATRIX_ADDR(m, i, j)];
}

void matrixSetValue(matrix* m, int i, int j, double value){
    // Check if matrix exists (is not null)
    if(m == NULL){
        fprintf(stderr, "Matrix does not exist.\n");
        return;
    }
    // Check if index is positive
    if(i < 0 || j < 0){
        fprintf(stderr, "Index could not be negative.\n");
        return;
    }
    // Check if index matches the matrix dimensions
    if(i >= m->rows || j >= m->cols){
        fprintf(stderr, "Index out of bounds.\n");
        return;
    }
    // Assing value to matrix element using the macro.
    m->data[MATRIX_ADDR(m, i, j)] = value;
    return;
}

matrix* matrixCreate(int rows, int cols){
    // Allocate memory for new matrix
    matrix* m = malloc(sizeof(matrix));
    // Check if allocation was successfull
    if(m == NULL){
        allocationFailure();
    }
    m->rows = rows;
    m->cols = cols;
    // Allocate memory for data array
    m->data = malloc(sizeof(double) * rows * cols);
    // Check if allocation was successfull
    if((m->data) == NULL){
        allocationFailure();
    }
    // Fill matrix with zeros
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrixSetValue(m, i, j, 0.0);
        }
    }
    // Return pointer to a new matrix
    return m;
}

void matrixDelete(matrix* m){
    // Free the matrix if it exists (non-null pointer).
    if(m != NULL){
        free(m);
    }
    return;
}

void matrixPrint(matrix* m){
    // Check if matrix exists (is not null)
    if(m == NULL){
        fprintf(stderr, "Matrix does not exist.\n");
        return;
    }
    // Print matrix to stdout
    fprintf(stdout, "\n");
    for(int i = 0; i < m->rows; i++){
        fprintf(stdout, "[ ");
        for(int j = 0; j < m->cols; j++){
            fprintf(stdout, "%.2lf ", matrixGetValue(m, i, j));
        }
        fprintf(stdout, "]\n");
    }
}

matrix* matrixMul(matrix* m1, matrix* m2){
    int rows = m1->rows;
    int cols = m2->cols;
    // Create a new matrix instance using the matrixCreate function.
    matrix* result = matrixCreate(rows, cols);
    // Check if matrices exist (are not null)
    if(m1 == NULL || m2 == NULL){
        fprintf(stderr, "At least one of the matrices isn't allocated.\n");
        return NULL;
    }
    // Verify that matrix dimensions meet the operation requirements.
    if(m1->cols != m2->rows){
        fprintf(stderr, "Matrix dimensions are incompatible for this operation.\n");
        return NULL;
    }
    // For each position (i, j) in the result matrix, calculate the sum
    // of element-wise products of row i from m1 and column j from m2.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double sum = 0.0;
            for (int k=0; k < m1->cols; k++) {
                sum += matrixGetValue(m1, i, k) * matrixGetValue(m2, k, j);
            }
            result->data[MATRIX_ADDR(result,i,j)] = sum;
        }
    }
    // Return pointer to a new matrix
    return result;
}

matrix* matrixMulScalar(matrix* m1, double value){
    // Check if matrix exists (is not null)
    if(m1 == NULL){
        fprintf(stderr, "Matrix does not exist.\n");
        return NULL;
    }
    int rows = m1->rows;
    int cols = m1->cols;

    // Create a new matrix instance using the matrixCreate function.
    matrix* result = matrixCreate(rows, cols);

    // Fill the new matrix with values from the original matrix, each multiplied by the scalar.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrixSetValue(result, i, j, matrixGetValue(m1, i, j) * value);
        }
    }
    // Return pointer to a new matrix
    return result;
}

matrix* matrixAddScalar(matrix* m1, double value){
    // Check if matrix exists (is not null)
    if(m1 == NULL){
        fprintf(stderr, "Matrix does not exist.\n");
        return NULL;
    }
    int rows = m1->rows;
    int cols = m1->cols;

    // Create a new matrix instance using the matrixCreate function.
    matrix* result = matrixCreate(rows, cols);

    // Fill the new matrix with values from the original matrix, each increased by the scalar.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrixSetValue(result, i, j, matrixGetValue(m1, i, j) + value);
        }
    }
    // Return pointer to a new matrix
    return result;
}

matrix* matrixSubScalar(matrix* m1, double value){
    // Check if matrix exists (is not null)
    if(m1 == NULL){
        fprintf(stderr, "Matrix does not exist.\n");
        return NULL;
    }
    int rows = m1->rows;
    int cols = m1->cols;

    // Create a new matrix instance using the matrixCreate function.
    matrix* result = matrixCreate(rows, cols);

    // Fill the new matrix with values from the original matrix, each decreased by the scalar.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrixSetValue(result, i, j, matrixGetValue(m1, i, j) - value);
        }
    }
    // Return pointer to a new matrix
    return result;
}

matrix* matrixAdd(matrix* m1, matrix* m2){
    // Check if matrices exist (are not null)
    if(m1 == NULL || m2 == NULL){
        fprintf(stderr, "At least one of the matrices isn't allocated.\n");
        return NULL;
    }
    // Verify that matrix dimensions meet the operation requirements.
    if(m1->cols != m2->cols || m1->rows != m2->rows){
        fprintf(stderr, "Matrix dimensions are incompatible for this operation.\n");
        return NULL;
    }
    int rows = m1->rows;
    int cols = m1->cols;

    // Create a new matrix instance using the matrixCreate function.
    matrix* result = matrixCreate(rows, cols);

    // Fill the new matrix with the sum of corresponding elements from m1 and m2.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrixSetValue(result, i, j, matrixGetValue(m1, i, j) + matrixGetValue(m2, i, j));
        }
    }
    // Return pointer to a new matrix
    return result;
}

matrix* matrixSub(matrix* m1, matrix* m2){
    // Check if matrices exist (are not null)
    if(m1 == NULL || m2 == NULL){
        fprintf(stderr, "At least one of the matrices isn't allocated.\n");
        return NULL;
    }

    // Verify that matrix dimensions meet the operation requirements.
    if(m1->cols != m2->cols || m1->rows != m2->rows){
        fprintf(stderr, "Matrix dimensions are incompatible for this operation.\n");
        return NULL;
    }
    int rows = m1->rows;
    int cols = m1->cols;

    // Create a new matrix instance using the matrixCreate function.
    matrix* result = matrixCreate(rows, cols);

    // Fill the new matrix with the difference of corresponding elements from m1 and m2.
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrixSetValue(result, i, j, matrixGetValue(m1, i, j) - matrixGetValue(m2, i, j));
        }
    }
    // Return pointer to a new matrix
    return result;
}

matrix* matrixTranspose(matrix* m){

    // Create a new matrix using matrixCreate with rows and columns swapped.
    matrix* matrixT = matrixCreate(m->cols, m->rows);

    // Set the value at (j, i) in the transposed matrix from the original matrix.
    for(int i = 0; i < matrixT->rows; i++){
        for(int j = 0; j < matrixT->cols; j++){
            matrixSetValue(matrixT, i, j, matrixGetValue(m, j, i));
        }
    }

    // Return pointer to a new matrix
    return matrixT;
}

double matrixDetChio(matrix* m){
    // Check if matrix exists (is not null)
    if(m == NULL){
        allocationFailure();
    }

    // Check if matrix is square
    if(m->cols != m->rows){
        fprintf(stderr, "Cannot compute determinant of a non-square matrix.\n");
        return -1;
    }
    // If the matrix is 1×1, the determinant is equal to its single element.
    if(m->cols == 1){
        return matrixGetValue(m, 0, 0);
    }
    // Calculate the determinant of a 2×2 matrix.
    if(m->cols == 2){
        return matrixGetValue(m, 0, 0) * matrixGetValue(m, 1, 1) - matrixGetValue(m, 0, 1) * matrixGetValue(m, 1, 0);
    }
    // Initialize coefficient c to 1. Used to track row swaps and scaling for Chio's determinant method.
    double c = 1;

    // If the top-left element is zero, swap the first row with a row below that has a non-zero element
    // to avoid division by zero in Chio's method.
    if(matrixGetValue(m, 0, 0) == 0){
        int swapped = 0;
        for(int k = 0; k < m->rows && !swapped; k++){
            if(matrixGetValue(m, k, 0) != 0){
                for(int j = 0; j < m->cols; j++){
                    double tmp = matrixGetValue(m, 0, j);
                    matrixSetValue(m, 0, j, matrixGetValue(m, k, j));
                    matrixSetValue(m, k, j, tmp);
                    c = -c;
                    swapped = 1;
                }
            }
        }
    }

    // If the first column contains only zeros, the determinant is zero (matrix is singular)
    if(matrixGetValue(m, 0, 0) == 0){
        fprintf(stderr, "The first column of the matrix contains only zeros.\n");
        return -1;
    }

    // Create a (n-1)x(n-1) matrix for recursive calculation in Chio's method
    matrix* mTmp = matrixCreate(m->rows-1, m->cols-1);

    // Adjust coefficient c according to Chio's formula
    c = c/pow(matrixGetValue(m, 0, 0), m->cols-2);

    // Fill the smaller matrix with values computed according to Chio's determinant formula
    for(int i = 0; i < m->rows-1; i++){
        for(int j = 0; j < m->cols-1; j++){
            matrixSetValue(mTmp, i, j, matrixGetValue(m, 0, 0) * matrixGetValue(m, i+1, j+1) - matrixGetValue(m, i+1, 0)*matrixGetValue(m, 0, j+1));
        }
    }
    // Recursively calculate determinant of the smaller matrix and apply coefficient c
    double result = c * matrixDetChio(mTmp);

    // Free memory of temporary matrix
    matrixDelete(mTmp);

    // Return the computed determinant (double)
    return result;
}