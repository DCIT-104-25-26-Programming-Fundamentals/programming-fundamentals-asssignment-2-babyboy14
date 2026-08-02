// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Maximum size declared as per assignment requirements
const int MAX_SIZE = 10;

// Helper function to print a matrix neatly using setw()
void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// Helper function to input matrix elements from the user
void inputMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "\nEnter elements for Matrix " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// PART A — Transpose a Matrix (M x N -> N x M)
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

// PART B — Add Two Matrices (M x N)
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C — Multiply Two Matrices (A: M x N, B: N x P -> Result: M x P)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize cell accumulator
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    cout << "=========================================" << endl;
    cout << "          MATRIX OPERATIONS MENU         " << endl;
    cout << "=========================================" << endl;

    // -------------------------------------------------------------------------
    // PART A: TRANSPOSE DEMONSTRATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART A: Transpose a Matrix ---" << endl;
    int rA, cA;
    cout << "Enter number of rows: ";
    cin >> rA;
    cout << "Enter number of columns: ";
    cin >> cA;

    int matA[MAX_SIZE][MAX_SIZE];
    int transResult[MAX_SIZE][MAX_SIZE];

    inputMatrix(matA, rA, cA, "A");

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matA, rA, cA);

    transposeMatrix(matA, transResult, rA, cA);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transResult, cA, rA); // Note: Dimensions swap to cA x rA

    // -------------------------------------------------------------------------
    // PART B: ADDITION DEMONSTRATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    int rB, cB;
    cout << "Enter number of rows for matrices: ";
    cin >> rB;
    cout << "Enter number of columns for matrices: ";
    cin >> cB;

    int matB1[MAX_SIZE][MAX_SIZE];
    int matB2[MAX_SIZE][MAX_SIZE];
    int addResult[MAX_SIZE][MAX_SIZE];

    inputMatrix(matB1, rB, cB, "1");
    inputMatrix(matB2, rB, cB, "2");

    addMatrices(matB1, matB2, addResult, rB, cB);

    cout << "\nSum Matrix:" << endl;
    printMatrix(addResult, rB, cB);

    // -------------------------------------------------------------------------
    // PART C: MULTIPLICATION DEMONSTRATION
    // -------------------------------------------------------------------------
    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    int rM1, cM1, rM2, cM2;
    cout << "Enter rows for Matrix A: ";
    cin >> rM1;
    cout << "Enter columns for Matrix A (will match rows of Matrix B): ";
    cin >> cM1;

    rM2 = cM1; // Condition: Columns of A must equal Rows of B
    cout << "Enter columns for Matrix B: ";
    cin >> cM2;

    int multA[MAX_SIZE][MAX_SIZE];
    int multB[MAX_SIZE][MAX_SIZE];
    int multResult[MAX_SIZE][MAX_SIZE];

    inputMatrix(multA, rM1, cM1, "A");
    inputMatrix(multB, rM2, cM2, "B");

    multiplyMatrices(multA, multB, multResult, rM1, cM1, cM2);

    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(multResult, rM1, cM2); // Dimensions are rM1 x cM2

    return 0;
}
