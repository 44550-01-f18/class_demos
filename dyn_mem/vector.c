#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int arr_size = 15;
	int * my_array = malloc(arr_size*sizeof(int));
	for (int i=0; i<arr_size; i++)
	{
		my_array[i] = i * i + 3;
	}

	for (int i=0; i<arr_size; i++)
		printf("%d ", my_array[i]);
	printf("\n");

	int * temp = my_array;

	my_array = malloc(arr_size * 2 * sizeof(int));

	for (int i=0; i<arr_size; i++)
		my_array[i] = temp[i];
	
	arr_size *= 2;
	// my_al.add(3)
	// my_list.append(3)

	return 0;
}
