#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void printLowerMatrix(int** mat, int rows,int cols);
void printUpperMatrix(int** mat, int rows, int cols);
void changeRows(void** mat, int row1, int row2);
void changeCols(int** mat, int rows, int col1, int col2);
int** LowerTriangularMatrix(int rows, int cols);
int** UpperTriangularMatrix(int rows, int cols);

int main()
{
	int** new_mat = NULL;
	new_mat = UpperTriangularMatrix(ROWS,COLS);
	printUpperMatrix(new_mat, ROWS, COLS);
	return 0;
}

void printLowerMatrix(int** mat, int rows,int cols)
{
	printf("\n\nPrinting the matrix: \n\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <= i; j++) // with 0's: j < cols
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

void printUpperMatrix(int** mat, int rows,int cols)
{
	printf("\n\nPrinting the matrix: \n\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) // with 0's: j = 0
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

void changeRows(void** mat, int row1, int row2)
{
	void* temp = mat[row1];
	mat[row1] = mat[row2];
	mat[row2] = temp;
}

void changeCols(int** mat,int rows, int col1, int col2)
{
	int temp;
	for (int i = 0; i < rows; i++)
	{
		temp = mat[i][col1];
		mat[i][col1] = mat[i][col2];
		mat[i][col2] = temp;
	}
}

int** LowerTriangularMatrix(int rows, int cols)
{
	int** lower_mat = NULL,col_size = 0,count = 1;
	lower_mat = (int**)calloc(rows, sizeof(int*));
	if (!lower_mat) return NULL;

	for (int i = 0; i<rows; i++)
	{
		lower_mat[i] = (int*)calloc(++col_size,sizeof(int)); // with 0's: lower_mat[i] = (int*)calloc(cols,sizeof(int));
		if (!lower_mat) return NULL;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			lower_mat[i][j] = count;
		}
		count++;
	}

	return lower_mat;
}

int** UpperTriangularMatrix(int rows, int cols)
{
	int** upper_mat = NULL, col_size = 0, count = 1;
	upper_mat = (int**)calloc(rows, sizeof(int*));
	if (!upper_mat) return NULL;

	for (int i = rows - 1; i >= 0; i--)
	{
		upper_mat[i] = (int*)calloc(cols, sizeof(int)); // with 0's: upper_mat[i] = (int*)calloc(cols, sizeof(int));
		if (!upper_mat) return NULL;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = i; j < cols; j++)
		{
			upper_mat[i][j] = count;
		}
		count++;
	}

	return upper_mat;
}