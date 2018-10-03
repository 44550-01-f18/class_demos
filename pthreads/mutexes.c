#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int anumber;
pthread_mutex_t data_mutex;

void *th1(void *args);
void *th2(void *args);

int main()
{
  anumber = 3;
  pthread_t t1, t2;
  void *nothing;
  int i;
  pthread_mutex_init(&data_mutex, NULL);
  pthread_create(&t1, NULL, th1, NULL);
  pthread_create(&t2, NULL, th2, NULL);
  pthread_join(t1, &nothing);
  pthread_join(t2, &nothing);
  printf("anumber is: %d\n", anumber);
  pthread_mutex_destroy(&data_mutex);
  return 0;
}

void *th1(void *args)
{
  int i = 0;
  pthread_mutex_lock(&data_mutex);
  anumber *= 2;
  for (; i < 1000000; i++)
    ;
  anumber++;
  pthread_mutex_unlock(&data_mutex);
  pthread_exit(NULL);
}

void *th2(void *args)
{
  int i = 0;
  pthread_mutex_lock(&data_mutex);
  anumber /= 2;
  for (; i < 1000000; i++)
    ;
  anumber--;
  pthread_mutex_unlock(&data_mutex);
  pthread_exit(NULL);
}
