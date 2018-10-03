#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex1, mutex2;
void *thread1(void *args);
void *thread2(void *args);

int main()
{
  pthread_t t1, t2;
  void *screwit;
  pthread_mutex_init(&mutex1, NULL);
  pthread_mutex_init(&mutex2, NULL);

  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  pthread_join(t1, &screwit);
  pthread_join(t2, &screwit);

  pthread_mutex_destroy(&mutex1);
  pthread_mutex_destroy(&mutex2);
}

void *thread1(void *args)
{
  pthread_mutex_lock(&mutex1);
  for (int i = 0; i < 10000; i++)
    ;
  pthread_mutex_lock(&mutex2);
  printf("FIRE ZE MISSILES!\n");
  pthread_mutex_unlock(&mutex1);
  pthread_mutex_unlock(&mutex2);
}
void *thread2(void *args)
{
  pthread_mutex_lock(&mutex2);
  for (int i = 0; i < 10000; i++)
    ;
  pthread_mutex_lock(&mutex1);
  printf("FIRE ZE OZZER MISSILES!\n");
  pthread_mutex_unlock(&mutex1);
  pthread_mutex_unlock(&mutex2);
}
