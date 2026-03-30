// Class Work 4 - Linked Lists

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int data;
	struct element* next;
}element;

int createLinkedList(element** even, element** odd);
int LinkedListSum(element* list, int* min, int* max);
void PrintList(element* list);
void FreeList(element* list);

int main()
{
	element* even, * odd;
	int count, min_even, max_even,sum_even, min_odd,max_odd, sum_odd;
	count = createLinkedList(&even, &odd);
	sum_even = LinkedListSum(even, &min_even, &max_even);
	sum_odd = LinkedListSum(odd, &min_odd, &max_odd);

	printf("\n");
	PrintList(even);
	printf("\n");
	printf("even sum = %d\nmin even number = %d\nmax even number = %d\n", sum_even, min_even, max_even);
	printf("\n");
	PrintList(odd);
	printf("\n");
	printf("odd sum = %d\nmin odd number = %d\nmax odd number = %d\n", sum_odd, min_odd, max_odd);
	printf("\n");
	printf("number of numbers in the lists: %d\n", count);

	FreeList(even);
	FreeList(odd);

	return 0;
}

int createLinkedList(element** even, element** odd)
{
	int count = 0, x;
	element* temp_even, * temp_odd;
	*even = (element*)malloc(sizeof(element));
	*odd = (element*)malloc(sizeof(element));
	temp_even = *even;
	temp_odd = *odd;

	printf("Enter a number: ");
	scanf("%d", &x);
	while (x != -1)
	{
		if (x % 2 == 0)
		{
			temp_even->next = (element*)malloc(sizeof(element)); //create the next element
			temp_even = temp_even->next; // take the temp element to the next element, now the first element is dummy
			temp_even->data = x; // insert numbers to the second element and above
		}
		else
		{
			temp_odd->next = (element*)malloc(sizeof(element));
			temp_odd = temp_odd->next;
			temp_odd->data = x;
		}
		count++;
		scanf("%d", &x);
	}
	temp_even->next = temp_odd->next = NULL;

	temp_even = *even;
	*even = (*even)->next;
	free(temp_even);

	temp_odd = *odd;
	*odd = (*odd)->next;
	free(temp_odd);

	return count;
}

int LinkedListSum(element* list, int* min, int* max)
{
	int sum = 0;
	*min = *max = list->data;
	list = list->next;
	while (list)
	{
		if (list->data < *min)
		{
			*min = list->data;
		}
		else if (list->data > *max)
		{
			*max = list->data;
		}
		sum += list->data;
		list = list->next;
	}
	return sum;
}

void PrintList(element* list)
{
	element* temp = list;
	while (temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void FreeList(element* list)
{
	element* temp = NULL;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}