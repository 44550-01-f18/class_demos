/*!
 * \file smarter_bitonic.c
 * \brief Implements a completely threaded bitonic sort
 * \author Nathan Eloe
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _to_bitonic_sort {
  int *arr;
  int size;
  int direction;
} bitonic;

/*
 * brief: starts a new thread that runs the thr_bitonic function with b as an
 *        arg
 * returns: the thread identifier
 */
pthread_t launch_thread(bitonic *b);
/*
 * brief: bitonically sorts the portion of the array specified
 *        specified by the arg (of type bitonic *) by launching threads for each
 *        half
 */
void *thr_bitonic(void *arg);
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
  void *status;
  bitonic b;
  pthread_t tid;
  b.size = 1 << atoi(argv[1]);
  b.arr = malloc(sizeof(int) * b.size);
  b.direction = 1;
  randofill(b.arr, b.size);
  // print_array(b.arr, b.size);
  tid = launch_thread(&b);
  pthread_join(tid, &status);
  //pthread_join(launch_thread(&b), &status);
  // print_array(b.arr, b.size);
  free(b.arr);
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

pthread_t launch_thread(bitonic *b)
{
  pthread_t th;
  pthread_create(&th, NULL, thr_bitonic, (void *)b);
  return th;
}

void *thr_bitonic(void *arg)
{
  bitonic *bit = (bitonic *)arg;
  bitonic h1 = {bit->arr, bit->size / 2, 1};
  /*
   * bitonic h1;
   * h1.arr = bit->arr;
   * h1.size = bit.size/2;
   * h1.direction = 1;
   * */
  bitonic h2 = {&(bit->arr[bit->size / 2]), bit->size - bit->size / 2, 0};
  pthread_t t1, t2;
  void *status;
  if (bit->size > 1) {
    // int * midpt = &(bit->arr[bit->size / 2];
    t1 = launch_thread(&h1);
    t2 = launch_thread(&h2);
    pthread_join(t1, &status);
    pthread_join(t2, &status);
    seq_bitonic_merge(bit->direction, bit->arr, bit->size);
  }
  pthread_exit(NULL);
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
