#ifndef MATRIX_H
#define MATRIX_H

/**
 * Compute the linear index in the matrix data array.
 *
 * Given a matrix pointer `m`, row index `i`, and column index `j`,
 * this macro returns the corresponding 1D index in the `data` array
 * stored in row-major order.
 */
#define MATRIX_ADDR(m, i, j) ((i) * ((m)->cols) + (j))

/**
 * Structure representing a dynamic matrix stored in row-major order.
 */
typedef struct {
    int rows;       /** Number of rows in the matrix */
    int cols;       /** Number of columns in the matrix */
    double* data;   /** Pointer to the matrix elements */
} matrix;

/**
 * Get the value at position (i, j) in the matrix.
 * @param m Pointer to the matrix
 * @param i Row index
 * @param j Column index
 * @return The value stored at position (i, j)
 */
double matrixGetValue(matrix* m, int i, int j);

/**
 * Set the value at position (i, j) in the matrix.
 * @param m Pointer to the matrix
 * @param i Row index
 * @param j Column index
 * @param value Value to set at (i, j)
 */
void matrixSetValue(matrix* m, int i, int j, double value);

/**
 * Create a new matrix with given dimensions.
 * Function allocates memory for the matrix automatically.
 * @param rows Number of rows
 * @param cols Number of columns
 * @return Pointer to the newly created matrix
 */
matrix* matrixCreate(int rows, int cols);

/**
 * Free the memory associated with the matrix.
 * @param m Pointer to the matrix to delete
 */
void matrixDelete(matrix* m);

/**
 * Print the matrix to stdout.
 * @param m Pointer to the matrix to print
 */
void matrixPrint(matrix* m);

/**
 * Multiply two matrices (m1 × m2).
 * Function allocates memory for the matrix automatically.
 * @param m1 Pointer to the first matrix
 * @param m2 Pointer to the second matrix
 * @return Pointer to the resulting matrix, or NULL if dimensions are invalid
 */
matrix* matrixMul(matrix* m1, matrix* m2);

/**
 * Add two matrices (m1 + m2).
 * Function allocates memory for the matrix automatically.
 * @param m1 Pointer to the first matrix
 * @param m2 Pointer to the second matrix
 * @return Pointer to the resulting matrix, or NULL if dimensions mismatch
 */
matrix* matrixAdd(matrix* m1, matrix* m2);

/**
 * Multiply all elements of a matrix by a scalar value.
 * Function allocates memory for the matrix automatically.
 * @param m1 Pointer to the matrix
 * @param value Scalar value to multiply
 * @return Pointer to the resulting matrix
 */
matrix* matrixMulScalar(matrix* m1, double value);

/**
 * Add a scalar value to all elements of the matrix.
 * Function allocates memory for the matrix automatically.
 * @param m1 Pointer to the matrix
 * @param value Scalar value to add
 * @return Pointer to the resulting matrix
 */
matrix* matrixAddScalar(matrix* m1, double value);

/**
 * Subtract a scalar value from all elements of the matrix.
 * Function allocates memory for the matrix automatically.
 * @param m1 Pointer to the matrix
 * @param value Scalar value to subtract
 * @return Pointer to the resulting matrix
 */
matrix* matrixSubScalar(matrix* m1, double value);

/**
 * Subtract two matrices (m1 - m2).
 * Function allocates memory for the matrix automatically.
 * @param m1 Pointer to the first matrix
 * @param m2 Pointer to the second matrix
 * @return Pointer to the resulting matrix, or NULL if dimensions mismatch
 */
matrix* matrixSub(matrix* m1, matrix* m2);

/**
 * Compute the transpose of a matrix.
 * Function allocates memory for the matrix automatically.
 * @param m Pointer to the matrix
 * @return Pointer to the transposed matrix
 */
matrix* matrixTranspose(matrix* m);

/**
 * Compute the determinant of a matrix using Chio's method.
 * Works only for square matrices.
 * @param m Pointer to the square matrix
 * @return Determinant of the matrix
 * 
 * Source: https://matematyka.pl/viewtopic.php?t=360950
 */
double matrixDetChio(matrix* m);

#endif /* MATRIX_H */
