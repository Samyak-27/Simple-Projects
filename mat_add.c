//Program to add two matrices
#include <stdio.h>

// Function to read a matrix from the user
void readMatrix(int rows, int cols, int matrix[rows][cols]) {//takes in rows, columns and matrix with the given dimension
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {//takes in rows, columns and both the matrix with the given dimensions
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {//takes in rows, colums and a matrix with the given dimension
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Please enter the number of rows: ");
    scanf("%d", &rows);//user input for rows
    printf("Please enter the number of columns: ");
    scanf("%d", &cols);//user input for columns

    int matrixA[rows][cols]; //creating a matrix A with the required dimensions
    int matrixB[rows][cols]; // creating a matrix B with the required dimensions
    int result[rows][cols]; //creating a result matrix with the required dimensions

    printf("Enter Matrix A\n");
    readMatrix(rows, cols, matrixA);

    printf("Enter Matrix B\n");
    readMatrix(rows, cols, matrixB);

    addMatrices(rows, cols, matrixA, matrixB, result);

    printf("A + B =\n");
    printMatrix(rows, cols, result);//prints the final matrix

    return 0;
}