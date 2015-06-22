#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 10

void squareMatrixMultiply(
        /*in*/  const int  length,
        /*in*/  int  matrix_a[][length],
        /*in*/  int  matrix_b[][length],
        /*out*/ int  matrix_c[][length])
{
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            matrix_c[i][j] = 0;
            for (int k = 0; k < length; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int test_matrix_a[MAX_NUM][MAX_NUM] =
            {{4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9}};

    int test_matrix_b[MAX_NUM][MAX_NUM] =
            {{4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9},
            {4, 2, 5, 1, 6, 7, 8, 3, 0, 9}};

    int matrix_c[MAX_NUM][MAX_NUM];
    squareMatrixMultiply(MAX_NUM, test_matrix_a, test_matrix_b, matrix_c);
    
    printf("The multiply result matrix is:\n");

    for (int i = 0; i <  MAX_NUM; i++) {
        for (int j = 0; j <  MAX_NUM; j++) {
            printf("%d\t", matrix_c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}
