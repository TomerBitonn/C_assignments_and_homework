#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int strlen(char* str);
void swap(char* str1, char* str2);
int replaceString(char* str);
void countChars(char* str, int* small, int* big, int* digits, int* other);
void deleteSpaces(char* str);

int main()
{
	int x;
	char str1[] = "ekuirb7567AAT00l--%$#er5";
	char str2[] = "abcdcba";
	char str3[] = "I    live      in    Israel";
	int small, big, digits, other;

	// Ex1
	x = replaceString(&str2);
	printf("%d\n%s\n\n", x, str2);

	// Ex2
	countChars(str1, &small, &big, &digits, &other);
	printf("small = %d\nbig = %d\ndigits = %d\nother = %d\n\n", small, big, digits, other);

	// Ex3
	deleteSpaces(&str3);
	printf("%s\n\n", str3);

	return 0;
}

int strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}

void swap(char* str1, char* str2)
{
	char temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

// Ex1
int replaceString(char* str)
{
	char* last;
	int len = strlen(str), i, j, flag = 1;

	for (i = 0, j = 1; i <= len / 2; i++, j++)
	{
		if (str[len - j] != str[i])
		{
			swap(&str[len - j], &str[i]);
			flag = 0;
		}
	}
	return flag;
}

// Ex2
void countChars(char* str, int* small, int* big, int* digits, int* other)
{
	int len = strlen(str), i;
	*small = *big = *digits = *other = 0;

	for (i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			(*small)++;

		else if (str[i] >= 'A' && str[i] <= 'Z')
			(*big)++;

		else if (str[i] >= '0' && str[i] <= '9')
			(*digits)++;

		else
			(*other)++;
	}
}

// Ex3
void deleteSpaces(char* str)
{
	int len = strlen(str), i, j;

	for (i = 1, j = -1; i <= len; i++)
	{
		if (str[i] != str[i - 1])
		{
			j++;
			str[j] = str[i - 1];
		}
	}
	str[++j] = '\0';
}