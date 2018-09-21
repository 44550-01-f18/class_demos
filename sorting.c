#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b);
void shuffle(int arr[], int size);
void sort(int arr[], int size);
void print_arr(int arr[], int size);

int main(int argc, char* argv[])
{
	int my_arry [] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_arr(my_arry, 9);
	shuffle(my_arry, 9);
	print_arr(my_arry, 9);
	sort(my_arry, 9);
	print_arr(my_arry, 9);
	return 0;
}

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void shuffle(int arr[], int size)
{	
	int nextidx;
	for (int i=0; i<size-1; i++)
	{
		nextidx = rand() %(size - i);
		swap(&arr[i], &arr[i+nextidx]);
	}
}

void sort(int arr[], int size)
{
	for (int i=0; i<size-1; i++)
	{
		for (int j=0; j<size-1; j++)
		{
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

void print_arr(int arr[], int size)
{
	for (int i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}




