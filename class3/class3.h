#pragma once

// structs
typedef struct
{
	char adress[30];
	int rooms;
	double price;
}Apartment;

// declarations
void print_arr(Apartment* arr, int arr_size);
Apartment* new_neghiborhood(Apartment* apart_units, int apart_size, int num_of_rooms, int price, int* arr_size);
