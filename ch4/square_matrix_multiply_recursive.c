#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 8

typedef struct {
    int row_x;
    int col_x;
    int row_y;
    int col_y;
} partition;

void initMatrix(const int length, int matrix[][length])
{
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            matrix[i][j] = 0;
        }
    }
}

void printMatrix(const int length, int matrix[][length])
{
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void makePartition(int i, int j,
        partition part_in,  partition* part_out)
{
    int mid = (part_in.row_y - part_in.row_x) / 2;


    if (0 == i) {
        part_out->row_x = part_in.row_x;
        part_out->row_y = part_out->row_x + mid;
    } else {
        part_out->row_x = part_in.row_x + mid + 1;
        part_out->row_y = part_in.row_y;
    }

    if (0 == j) {
        part_out->col_x = part_in.col_x;
        part_out->col_y = part_out->col_x + mid;
    } else {
        part_out->col_x = part_in.col_x + mid + 1;
        part_out->col_y = part_in.col_y;
    }
}

//partion array_a, array_b, and array_c
//a1_1   . . . a1_n/2   | a1_n/2    . . . a1_n
//  .    . . .   .      |  .        . . . .
//  .    . . .   .      |  .        . . . .
//  .    . . .   .      |  .        . . . .
//an/2_1 . . . an/2_n/2 |  an/2_n/2 . . . an/2_n row n/2
//----------------------|-----------------------
//an/2_1 . . . an/2_n/2 |  an/2_n/2 . . . an/2_n row n/2+1
//  .    . . .   .      |  .        . . . .
//  .    . . .   .      |  .        . . . .
//  .    . . .   .      |  .        . . . .
//an_1   . . . an_n/2   |  an_n/2   . . . an_n
//          column n/2  |   n/2+1
//
//A11: array_a[1][1] --> array_a[n/2][n/2]
//A12: array_a[1][n/2+1] --> array_a[n/2][n]
//A21: array_a[n/2+1][1] --> array_a[n][n/2]
//A22: array_a[n/2+1][n/2+1] --> array_a[n][n]
//in c program language matrix start from a[0][0] to a[n-1][n-1]
void squareMatrixMultipyRecursive(
        const int length,
        int matrix_a[][MAX_NUM],
        int matrix_b[][MAX_NUM],
        int matrix_c[][MAX_NUM],
        partition part_a,
        partition part_b,
        partition part_c)
{
    if (1 == length) {
        /*printf("C: %d-%d, A: %d-%d, B: %d-%d\n",
                part_c.row_x, part_c.col_x,
                part_a.row_x, part_a.col_x,
                part_b.row_x, part_b.col_x);
        */
        
        matrix_c[part_c.row_x][part_c.col_x] +=
            matrix_a[part_a.row_x][part_a.col_x] * matrix_b[part_b.row_x][part_b.col_x];
    } else {
        int mid = length / 2;

        partition partitions_a[2][2], partitions_b[2][2], partitions_c[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                makePartition(i, j, part_a, &partitions_a[i][j]);
                /*
                printf("a-%d-%d: {%d, %d, %d, %d}\n", i, j,
                        partitions_a[i][j].row_x, partitions_a[i][j].col_x,
                        partitions_a[i][j].row_y, partitions_a[i][j].col_y);
                */

                makePartition(i, j, part_b, &partitions_b[i][j]);
                /*
                printf("b-%d-%d: {%d, %d, %d, %d}\n", i, j,
                        partitions_b[i][j].row_x, partitions_b[i][j].col_x,
                        partitions_b[i][j].row_y, partitions_b[i][j].col_y);

                */
                makePartition(i, j, part_c,  &partitions_c[i][j]);
                /*
                printf("c-%d-%d: {%d, %d, %d, %d}\n", i, j,
                        partitions_c[i][j].row_x, partitions_c[i][j].col_x,
                        partitions_c[i][j].row_y, partitions_c[i][j].col_y);
                */
            }
            //printf("\n");
        }

        squareMatrixMultipyRecursive(
                mid, matrix_a, matrix_b, matrix_c,
                partitions_a[0][0], partitions_b[0][0], partitions_c[0][0] );
        squareMatrixMultipyRecursive(
                mid, matrix_a, matrix_b, matrix_c,
                partitions_a[0][1], partitions_b[1][0], partitions_c[0][0] );

        squareMatrixMultipyRecursive(
                mid, matrix_a, matrix_b, matrix_c,
                partitions_a[0][0], partitions_b[0][1], partitions_c[0][1] );
        squareMatrixMultipyRecursive(
                mid, matrix_a, matrix_b, matrix_c,
                partitions_a[0][1], partitions_b[1][1], partitions_c[0][1] );

        squareMatrixMultipyRecursive(
                mid, matrix_a, matrix_b, matrix_c,
                partitions_a[1][0], partitions_b[0][0], partitions_c[1][0] );
        squareMatrixMultipyRecursive(
                mid, matrix_a, matrix_b, matrix_c,
                partitions_a[1][1], partitions_b[1][0], partitions_c[1][0] );

        squareMatrixMultipyRecursive(
                mid, matrix_a, matrix_b, matrix_c,
                partitions_a[1][0], partitions_b[0][1], partitions_c[1][1] );
        squareMatrixMultipyRecursive(
                mid, matrix_a, matrix_b, matrix_c,
                partitions_a[1][1], partitions_b[1][1], partitions_c[1][1] );
    }
}
int main() {
    int matrix_a[MAX_NUM][MAX_NUM] = 
        {{4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3}};
    int matrix_b[MAX_NUM][MAX_NUM] = 
        {{4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3},
         {4, 2, 5, 1, 6, 7, 8, 3}};

    int matrix_c[MAX_NUM][MAX_NUM];
    initMatrix(MAX_NUM, matrix_c);
    
    partition part_a  = {0, 0, MAX_NUM - 1, MAX_NUM - 1};
    partition part_b  = {0, 0, MAX_NUM - 1, MAX_NUM - 1};
    partition part_c  = {0, 0, MAX_NUM - 1, MAX_NUM - 1};

    printf("matrix a is:\n");
    printMatrix(MAX_NUM, matrix_a);
    
    printf("matrix b is:\n");
    printMatrix(MAX_NUM, matrix_b);
    
    squareMatrixMultipyRecursive(MAX_NUM,
            matrix_a, matrix_b, matrix_c,
            part_a, part_b, part_c);

    printf("matrix c is:\n");
    printMatrix(MAX_NUM, matrix_c);
    return 0;
}
