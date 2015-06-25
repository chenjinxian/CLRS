#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 2

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

void squareMatrixAdd(
	const int length,
	int matrix_a[][MAX_NUM],
	int matrix_b[][MAX_NUM],
	int matrix_c[][MAX_NUM])
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			matrix_c[i][j] = matrix_a[i][j] + matrix_b[i][j];
		}
	}
}

void squareMatrixPlus(
	const int length,
	int matrix_a[][MAX_NUM],
	int matrix_b[][MAX_NUM],
	int matrix_c[][MAX_NUM])
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			matrix_c[i][j] = matrix_a[i][j] - matrix_b[i][j];
		}
	}
}

void squareMatrixMultiply(
	/*in*/  const int  length,
	/*in*/  int  matrix_a[][MAX_NUM],
	/*in*/  int  matrix_b[][MAX_NUM],
	/*out*/ int  matrix_c[][MAX_NUM])
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

void squareMatrixMultipyStrassen(
	const int length,
	int matrix_a[][MAX_NUM],
	int matrix_b[][MAX_NUM],
	int matrix_c[][MAX_NUM])
{
	if (2 == length) {
		squareMatrixMultiply(length, matrix_a, matrix_b, matrix_c);
	} else {
		const int mid = length / 2;

		int part_a11[MAX_NUM][MAX_NUM], part_a12[MAX_NUM][MAX_NUM],
			part_a21[MAX_NUM][MAX_NUM], part_a22[MAX_NUM][MAX_NUM];
		int part_b11[MAX_NUM][MAX_NUM], part_b12[MAX_NUM][MAX_NUM],
			part_b21[MAX_NUM][MAX_NUM], part_b22[MAX_NUM][MAX_NUM];     
		int part_c11[MAX_NUM][MAX_NUM], part_c12[MAX_NUM][MAX_NUM],
			part_c21[MAX_NUM][MAX_NUM], part_c22[MAX_NUM][MAX_NUM];
		for (int i = 0; i < mid; i++) {
			for (int j = 0; j < mid; j++) {
				part_a11[i][j] = matrix_a[i][j];
				part_a12[i][j] = matrix_a[i][j + mid];
				part_a21[i][j] = matrix_a[i + mid][j];
				part_a22[i][j] = matrix_a[i + mid][j + mid];

				part_b11[i][j] = matrix_b[i][j];
				part_b12[i][j] = matrix_b[i][j+ mid];
				part_b21[i][j] = matrix_b[i + mid][j];
				part_b22[i][j] = matrix_b[i + mid][j + mid];    
			}
		}

		int matrix_s1[MAX_NUM][MAX_NUM], matrix_s2[MAX_NUM][MAX_NUM],
			matrix_s3[MAX_NUM][MAX_NUM], matrix_s4[MAX_NUM][MAX_NUM],
			matrix_s5[MAX_NUM][MAX_NUM], matrix_s6[MAX_NUM][MAX_NUM],
			matrix_s7[MAX_NUM][MAX_NUM], matrix_s8[MAX_NUM][MAX_NUM],
			matrix_s9[MAX_NUM][MAX_NUM], matrix_s0[MAX_NUM][MAX_NUM];

		int matrix_p1[MAX_NUM][MAX_NUM], matrix_p2[MAX_NUM][MAX_NUM],
			matrix_p3[MAX_NUM][MAX_NUM], matrix_p4[MAX_NUM][MAX_NUM],
			matrix_p5[MAX_NUM][MAX_NUM], matrix_p6[MAX_NUM][MAX_NUM],
			matrix_p7[MAX_NUM][MAX_NUM];

		squareMatrixPlus(mid, part_b12, part_b22, matrix_s1);
		squareMatrixMultipyStrassen(mid, part_a11, matrix_s1, matrix_p1);

		squareMatrixAdd(mid, part_a11, part_a12, matrix_s2);
		squareMatrixMultipyStrassen(mid, matrix_s2, part_b22, matrix_p2);

		squareMatrixAdd(mid, part_a21, part_a22, matrix_s3);
		squareMatrixMultipyStrassen(mid, matrix_s3, part_b11, matrix_p3);

		squareMatrixPlus(mid, part_b21, part_b11, matrix_s4);
		squareMatrixMultipyStrassen(mid, part_a22, matrix_s4, matrix_p4);

		squareMatrixAdd(mid, part_a11, part_a22, matrix_s5);
		squareMatrixAdd(mid, part_b11, part_b22, matrix_s6);
		squareMatrixMultipyStrassen(mid, matrix_s5, matrix_s6, matrix_p5);

		squareMatrixPlus(mid, part_a12, part_a22, matrix_s7);
		squareMatrixAdd(mid, part_b21, part_b22, matrix_s8);
		squareMatrixMultipyStrassen(mid, matrix_s7, matrix_s8, matrix_p6);

		squareMatrixPlus(mid, part_a11, part_b21, matrix_s9);
		squareMatrixAdd(mid, part_b11, part_b12, matrix_s0);
		squareMatrixMultipyStrassen(mid, matrix_s9, matrix_s0, matrix_p7);

		int matrix_temp[MAX_NUM][MAX_NUM];
		initMatrix(MAX_NUM, matrix_temp);
		squareMatrixAdd(mid, matrix_p5, matrix_p4, matrix_temp);
		squareMatrixPlus(mid, matrix_temp, matrix_p2, matrix_temp);
		squareMatrixAdd(mid, matrix_temp, matrix_p6, part_c11);

		squareMatrixAdd(mid, matrix_p1, matrix_p2, part_c12);

		squareMatrixAdd(mid, matrix_p3, matrix_p4, part_c21);

		initMatrix(MAX_NUM, matrix_temp);
		squareMatrixAdd(mid, matrix_p5, matrix_p1, matrix_temp);
		squareMatrixPlus(mid, matrix_temp, matrix_p3, matrix_temp);
		squareMatrixAdd(mid, matrix_temp, matrix_p7, part_c22);

		for (int i = 0; i < mid; i++) {
			for (int j = 0; j < mid; j++) {
				matrix_c[i][j] = part_c11[i][j];
				matrix_c[i][j + mid] = part_c12[i][j];
				matrix_c[i + mid][j] = part_c21[i][j];
				matrix_c[i + mid][j + mid] = part_c22[i][j];      
			}
		}
	}
}
int main() {
	int matrix_a[MAX_NUM][MAX_NUM] = 
	{{1, 3},
	{7, 5}};
	int matrix_b[MAX_NUM][MAX_NUM] = 
	{{6, 8},
	{4, 2}};

	int matrix_c[MAX_NUM][MAX_NUM];
	initMatrix(MAX_NUM, matrix_c);

	partition part  = {0, 0, MAX_NUM - 1, MAX_NUM - 1};

	printf("matrix a is:\n");
	printMatrix(MAX_NUM, matrix_a);

	printf("matrix b is:\n");
	printMatrix(MAX_NUM, matrix_b);

	squareMatrixMultipyStrassen(MAX_NUM, matrix_a, matrix_b, matrix_c);

	printf("matrix c is:\n");
	printMatrix(MAX_NUM, matrix_c);
	return 0;
}
