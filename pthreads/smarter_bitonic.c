/*!
 * \file smarter_bitonic.c
 * \brief Implements a smarter threaded bitonic sort
 * \author Nathan Eloe
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

typedef struct _to_bitonic_sort
{
  int * arr;
  int size;
  int direction;
} bitonic;

/*
 * brief: sequentially bitonically sorts the portion of the array specified
 *        specified by the arg (of type bitonic *)
 */
void* thr_bitonic(void * arg);
/*
 * brief: starts a new thread that runs the thr_bitonic function with b as an
 *        arg
 * returns: the thread identifier
 */
pthread_t launch_thread(bitonic * b);
/*
 * brief: sorts the array pointed to by arr using the bitonic sort.
 *        launches two threads to sort each of two halves of the array
 */
void magic_bitonic(const int direction, int * arr, const int size);
/*
 * brief: sorts the first size integers in the array pointed to by arr
 *        using the bitonic sorting method in the specified direction
 *        see: https://en.wikipedia.org/wiki/Bitonic_sorter
 */
void seq_bitonic(const int direction, int * arr, const int size);
/*
 * brief: performs the bitonic merge operation
 *        see: https://en.wikipedia.org/wiki/Bitonic_sorter
 */
void seq_bitonic_merge(const int direction, int * arr, const int size);
/*
 * brief: performs the bitonic comparison across the chunks
 */
void bitonic_compare(const int direction, int * arr, const int size);
/*
 * brief: swaps the values pointed at by v1 and v2
 */
void swap(int * v1, int * v2);
/*
 * brief: prints size elements of the array pointed at by arr
 * pre: size < = size allocated for the array
 */
void print_array(const int * arr, const int size);
/*
 * brief: randomly fills size elements of the array with numbers [0, 100)
 * pre: size < = size allocated for the array
 */
void randofill(int * arr, const int size);

int main(int argc, char* argv[])
{
  srand(time(0));
  int numnums = 1 << atoi(argv[1]);
  int * tosort = malloc(sizeof(int) * numnums);
  randofill(tosort, numnums);
  bitonic b;
  //print_array(tosort, numnums);
  magic_bitonic(1, tosort, numnums);
  //print_array(tosort, numnums);
  free(tosort);
  return 0;
}

void magic_bitonic(const int direction, int * arr, const int size)
{
    bitonic h1 = {arr, size / 2, 1};
    bitonic h2 = {&(arr[size / 2]), size - size / 2, 0};
    pthread_t th1, th2;
    void * status;
    if (size <= 1)
        return;
    th1 = launch_thread(&h1);
    th2 = launch_thread(&h2);
    pthread_join(th1, &status);
    pthread_join(th2, &status);
    seq_bitonic_merge(direction, arr, size);
}

void* thr_bitonic(void * arg)
{
  bitonic * bit = (bitonic *) arg;
  pthread_t t1, t2;
  void * status;
  if (bit -> size > 1)
  {
    seq_bitonic(1, bit->arr, bit->size / 2);
    seq_bitonic(0, &(bit->arr[bit->size / 2]), bit->size - bit->size / 2);
    seq_bitonic_merge(bit->direction, bit->arr, bit->size);
  }
  pthread_exit(NULL);
}

pthread_t launch_thread(bitonic * b)
{
  pthread_t th;
  pthread_create(&th, NULL, thr_bitonic, (void*) b);
  return th;
}

void randofill(int * arr, const int size)
{
  int i;
  for (i=0; i<size; i++)
    arr[i] = rand() % 100;
}

void swap(int * v1, int * v2)
{
  int temp = * v1;
  *v1 = *v2;
  *v2 = temp;
}

void seq_bitonic(const int direction, int * arr, const int size)
{
  if (size > 1)
  {
    int * midpt = &arr[size / 2];
    seq_bitonic(1, arr, size / 2);
    seq_bitonic(0, midpt, size - (size / 2));
    seq_bitonic_merge(direction, arr, size);
  }
}
void seq_bitonic_merge(const int direction, int * arr, const int size)
{
  if (size > 1)
  {
    int * midpt = &arr[size / 2];
    bitonic_compare(direction, arr, size);
    seq_bitonic_merge(direction, arr, size / 2);
    seq_bitonic_merge(direction, midpt, size - size / 2);
  }
}
void bitonic_compare(const int direction, int * arr, const int size)
{
  int dist = size / 2;
  int i;
  for (i=0; i<dist; i++)
  {
    if (arr[i] > arr[i + dist] == direction)
      swap(&arr[i], &arr[i+dist]);
  }
}

void print_array(const int * arr, const int size)
{
  int i;
  for (i = 0; i<size; i++)
    printf("%2.d ", arr[i]);
  printf("\n");
}
