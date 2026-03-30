#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* arr, int size);
void printCharArray(char* arr, int size);
void printStr(char* str);
int* createArrays(int* A, int n, int** odd_arr, int* odd_size, int* even_size);
void createCharArrays(char* arr, int n, char** capital, char** small, int* size_cap, int* size_small);
void createArrFromStr(char* str, char** capital, char** small, int* size_cap, int* size_small);
int* RemoveDup(int* arr, int n, int* size_arr);

int main()
{
	int arr[10] = { 50,60,60,72,81,81,81,81,93,93};
	printArray(arr, 10);
	int* new_arr, size_arr;
	new_arr = RemoveDup(arr, 10, &size_arr);
	printArray(new_arr, size_arr);
	free(new_arr);

	return 0;
}

void printArray(int* arr,int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d \n", arr[i]);
}

void printCharArray(char* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%c \n", arr[i]);
}

void printStr(char* str)
{
	int i, len = strlen(str);
	for(i =0;i< len;i++)
		printf("%c ", str[i]);
}

// Q1
int* createArrays(int* A, int n, int** odd_arr, int* odd_size, int* even_size)
{
	int* even_arr, i;
	*odd_size = *even_size = 0;

	even_arr = (int*)malloc(n * sizeof(int));
	*odd_arr = (int*)malloc(n * sizeof(int));
	if (!even_arr || !(*odd_arr)) return NULL;

	for (i = 0; i < n; i++)
	{
		if (A[i] % 2 == 0)
			even_arr[(*even_size)++] = A[i];
		else
			(*odd_arr)[(*odd_size)++] = A[i];
	}

	even_arr = (int*)realloc(even_arr,(*even_size) * sizeof(int));
	*odd_arr = (int*)realloc((*odd_arr), (*odd_size) * sizeof(int));
	if (!even_arr || !(*odd_arr)) return NULL;

	return even_arr;
}

//Q2
void createCharArrays(char* arr, int n, char** capital, char** small,int *size_cap, int *size_small)
{
	int capital_size = 0, small_size = 0, i;
	*capital = (char*)malloc(n * sizeof(char));
	*small = (char*)malloc(n * sizeof(char));
	if (!(*capital) || !(*small)) return NULL;

	for (i = 0; i < n; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			(*capital)[capital_size++] = arr[i];
		else if (arr[i] >= 'a' && arr[i] <= 'z')
			(*small)[small_size++] = arr[i];
	}

	*size_cap = capital_size;
	*size_small = small_size;

	*capital = (char*)realloc((*capital), capital_size * sizeof(char));
	*small = (char*)realloc((*small), small_size * sizeof(char));
	if (!(*capital) || !(*small)) return NULL;
}

//Q3
void createArrFromStr(char* str, char** capital, char** small, int* size_cap, int* size_small)
{
	*size_cap = *size_small = 0;
	int i, len = strlen(str);
	*capital = (char*)malloc(len * sizeof(char));
	*small = (char*)malloc(len * sizeof(char));
	if (!(*capital) || !(*small)) return NULL;

	for (i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			(*capital)[(*size_cap)++] = str[i];
		else if (str[i] >= 'a' && str[i] <= 'z')
			(*small)[(*size_small)++] = str[i];
	}

	*capital = (char*)realloc((*capital), (*size_cap) * sizeof(char));
	*small = (char*)realloc((*small), (*size_small) * sizeof(char));
	if (!(*capital) || !(*small)) return NULL;
}

//Q4
int* RemoveDup(int* arr, int n, int* size_arr)
{
	*size_arr = 0;
	int* new_arr = NULL, i;
	new_arr = (int*)malloc(n * sizeof(int));
	if (!new_arr) return NULL;

	for (i = 0; i < n; i++)
	{
		if (arr[i] != arr[i + 1])
			new_arr[(*size_arr)++] = arr[i];
	}

	new_arr = (int*)realloc(new_arr, (*size_arr) * sizeof(int));
	if (!new_arr) return NULL;

	return new_arr;
}