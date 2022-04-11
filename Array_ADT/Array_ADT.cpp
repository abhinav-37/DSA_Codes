// Array ADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
#ifdef _CRT_SECURE_NO_WARNINGS
#undef _CRT_SECURE_NO_WARNINGS
#endif
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<stdio.h>


struct Array
{
	int* A;
	int size;
	int length;
};

void display(struct Array arr) {
	printf("The array is \n");
	for (int i = 0; i < arr.length; i++)
	{
		printf("%d \n", arr.A[i]);
	}
}

void Append(struct Array *arr, int x) {
	if (arr->length < arr->size) {
		arr->A[arr->length++] = x;
	};
}

void Insert(struct Array* arr, int x, int index) {
	int i;
	if (index >= 0 && index <= arr->length) {
		for (i = arr->length; i > index; i--) {
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = x;
		arr->length++;
	}
}

int Delete(struct Array* arr, int index) {
	int deleted = 0;
	if (index < arr->length && index >= 0) {
		deleted = arr->A[index];
		for (int i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];
		arr->length-=1;
	}
	return deleted;
}

void Swap(struct Array* arr, int initial_index, int final_index) {
	int swap;
	swap = arr -> A[final_index];
	arr->A[final_index] = arr->A[initial_index];
	arr->A[initial_index] = swap;
}

int LinearSearch(struct Array arr, int key) {
	for (int i = 0; i < arr.length; i++) {
		if (arr.A[i] == key) {
			return i;
		}
	}

	return -1;
}

int LinearEnhancedWithTransposition(struct Array* arr, int key) {
	for (int i = 0; i< arr -> length; i++){
		if (arr->A[i] == key) {
			if (i != 0) {
				Swap(arr, i, i - 1);
			}
			return i;

		}
	}

	return -1;
}

int main()
{
	struct Array arr;
	printf("Please enter the size of the array: ");
	scanf("%d", &arr.size);

	//initializing the array
	arr.A = (int*)malloc(arr.size * (sizeof(int)));


	printf("\n Enter the total number of elements: ");
	scanf("%d", &arr.length);

	printf("Enter the elements: \n");
	for (int i = 0; i < arr.length; i++) {
		scanf("%d", &arr.A[i]);
	}

	//Append(&arr, 23);
	//Insert(&arr, 99, 2);
	//printf("The deleted element is %d\n", Delete(&arr, 2));
	printf("The found index is %d\n", LinearEnhancedWithTransposition(&arr, 12));
	display(arr);

}


