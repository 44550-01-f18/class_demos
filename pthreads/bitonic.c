/*!
 * \file bitonic.c
 * \brief Implements a sequential bitonic sort
 * \author Nathan Eloe
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * brief: sorts the first size integers in the array pointed to by arr
 *        using the bitonic sorting method in the specified direction
 *        see: https://en.wikipedia.org/wiki/Bitonic_sorter
 */
void seq_bitonic(const int direction, int *arr, const int size);
/*
 * brief: performs the bitonic merge operation
 *        see: https://en.wikipedia.org/wiki/Bitonic_sorter
 */
void seq_bitonic_merge(const int direction, int *arr, const int size);
/*
 * brief: performs the bitonic comparison across the chunks
 */
void bitonic_compare(const int direction, int *arr, const int size);
/*
 * brief: swaps the values pointed at by v1 and v2
 */
void swap(int *v1, int *v2);
/*
 * brief: prints size elements of the array pointed at by arr
 * pre: size < = size allocated for the array
 */
void print_array(const int *arr, const int size);
/*
 * brief: randomly fills size elements of the array with numbers [0, 100)
 * pre: size < = size allocated for the array
 */
void randofill(int *arr, const int size);

int main(int argc, char *argv[])
{
  srand(time(0));
  int numnums = 1 << atoi(argv[1]);
  int *tosort = malloc(sizeof(int) * numnums);
  randofill(tosort, numnums);
  //print_array(tosort, numnums);
  seq_bitonic(1, tosort, numnums);
  //print_array(tosort, numnums);
  free(tosort);
  return 0;
}

void randofill(int *arr, const int size)
{
  int i;
  for (i = 0; i < size; i++)
    arr[i] = rand() % 100;
}

void swap(int *v1, int *v2)
{
  int temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}

void seq_bitonic(const int direction, int *arr, const int size)
{
  if (size > 1) {
    int *midpt = &arr[size / 2];
    seq_bitonic(1, arr, size / 2);
    seq_bitonic(0, midpt, size - (size / 2));
    seq_bitonic_merge(direction, arr, size);
  }
}
void seq_bitonic_merge(const int direction, int *arr, const int size)
{
  if (size > 1) {
    int *midpt = &arr[size / 2];
    bitonic_compare(direction, arr, size);
    seq_bitonic_merge(direction, arr, size / 2);
    seq_bitonic_merge(direction, midpt, size - size / 2);
  }
}
void bitonic_compare(const int direction, int *arr, const int size)
{
  int dist = size / 2;
  int i;
  for (i = 0; i < dist; i++) {
    if (arr[i] > arr[i + dist] == direction)
      swap(&arr[i], &arr[i + dist]);
  }
}

void print_array(const int *arr, const int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%2.d ", arr[i]);
  printf("\n");
}
