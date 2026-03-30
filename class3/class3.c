#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "class3.h" 

// main
int main()
{
	Apartment house1 = { "Avokado 32", 5, 150 };
	Apartment house2 = { "Eshkolit", 5, 250 };
	Apartment house3 = { "Hagolan", 5, 100 };
	Apartment new_arr[3] = { house1, house2, house3 };
	int apart_size = 3, num_of_rooms, price, arr_size;
	printf("Enter number of rooms: ");
	scanf("%d", &num_of_rooms);
	printf("Enter max price: ");
	scanf("%d", &price);
	Apartment* arr_apartments = new_neghiborhood(new_arr, 3, num_of_rooms, price, &arr_size);
	print_arr(arr_apartments, arr_size);
	free(arr_apartments);
	return 0;
}

// functions
void print_arr(Apartment* arr, int arr_size)
{
	int i;
	for (i = 0; i < arr_size; i++)
	{
		printf("The adress is: %s\n", arr[i].adress);
		printf("Number of rooms: %d\n", arr[i].rooms);
		printf("Apartment price: %lf\n\n", arr[i].price);
	}
}

Apartment* new_neghiborhood(Apartment* apart_units, int apart_size, int num_of_rooms, int price, int *arr_size)
{
	int counter = 0;
	Apartment* new_arr = (Apartment*)malloc(apart_size * sizeof(Apartment));
	if (new_arr == NULL)
	{
		printf("Memory allocation failed.");
		exit(1);
	}
	for (int i = 0; i < apart_size; i++)
	{
		if (apart_units[i].price <= price && apart_units[i].rooms == num_of_rooms)
			new_arr[counter++] = apart_units[i];
	}
	*arr_size = counter;
	if (counter == 0)
		return NULL;
	return new_arr;
}  