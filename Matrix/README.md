# C Matrix implementation

This project contains a **matrix library implemented in C**, as part of learning algorithms and data structures.  

## Features

- Dynamic matrix creation and deletion
- Get and set matrix elements
- Matrix addition, subtraction, multiplication
- Scalar addition, subtraction, multiplication
- Transpose of a matrix
- Determinant calculation using **Chio's method**
- Error handling for invalid operations (dimension mismatch, singular matrix, etc.)

---

## Function Overview

### Creation & Deletion
- `matrix* matrixCreate(int rows, int cols)` – Create a new matrix
- `void matrixDelete(matrix* m)` – Free memory of a matrix

### Element Access
- `double matrixGetValue(matrix* m, int i, int j)` – Get element at (i,j)
- `void matrixSetValue(matrix* m, int i, int j, double value)` – Set element at (i,j)

### Arithmetic Operations
- `matrix* matrixAdd(matrix* m1, matrix* m2)` – Element-wise addition
- `matrix* matrixSub(matrix* m1, matrix* m2)` – Element-wise subtraction
- `matrix* matrixMul(matrix* m1, matrix* m2)` – Matrix multiplication
- `matrix* matrixAddScalar(matrix* m1, double value)` – Add scalar to all elements
- `matrix* matrixSubScalar(matrix* m1, double value)` – Subtract scalar from all elements
- `matrix* matrixMulScalar(matrix* m1, double value)` – Multiply all elements by scalar

### Other Operations
- `matrix* matrixTranspose(matrix* m)` – Transpose the matrix
- `double matrixDetChio(matrix* m)` – Determinant using Chio's method

### Example usage
- See `main.c` for a complete example of how to use the library.
