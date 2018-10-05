#include <pthread.h>
#include <stdio.h>

int globals_are_crap = 2;

void * thread1(void * args);
void * thread2(void * args);

int main(int argc, char* argv[])
{
	pthread_t th1, th2;
	void * status;
	pthread_create(&th1, NULL /*thread config options*/,
			thread1, NULL /*pointer to arguments to function*/);
	pthread_create(&th2, NULL, thread2, NULL);
	pthread_join(th1, &status);
	pthread_join(th2, &status);
	return 0;
}

void * thread1(void * args)
{
	for (int i=0; i<100; i++)
		globals_are_crap *= 1.5;
	printf("Thread 1: %d\n", globals_are_crap);
	pthread_exit(NULL);
}

void * thread2(void * args)
{
	for (int i=0; i<100; i++)
		globals_are_crap += 1;
	printf("Thread 2: %d\n", globals_are_crap);
	pthread_exit(NULL);
}
