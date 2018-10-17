#include <pthread.h>
#include <stdio.h>

void * alice(void * args);
void * bob(void * args);

pthread_mutex_t mutt_mut, chewToy_mut;

int main(int argc, char* argv[])
{
	pthread_t alice_th, bob_th;
	void * whoCares;
	
	pthread_mutex_init(&mutt_mut, NULL);
	pthread_mutex_init(&chewToy_mut, NULL);

	pthread_create(&alice_th, NULL, alice, NULL);
	pthread_create(&bob_th, NULL, bob, NULL);
	pthread_join(alice_th, &whoCares);
	pthread_join(bob_th, &whoCares);

	pthread_mutex_destroy(&mutt_mut);
	pthread_mutex_destroy(&chewToy_mut);
	return 0;
}

void * alice(void * args)
{
	pthread_mutex_lock(&chewToy_mut);
	for (int i=0; i<100000; i++);
	pthread_mutex_lock(&mutt_mut);
	printf("Alice is petting Chopstick\n");
	pthread_mutex_unlock(&chewToy_mut);
	pthread_mutex_unlock(&mutt_mut);
	pthread_exit(NULL);
}


void * bob (void * args)
{
	pthread_mutex_lock(&chewToy_mut);
	for (int i=0; i<100000; i++);
	pthread_mutex_lock(&mutt_mut);

	printf("Bob is petting Chopstick\n");
	pthread_mutex_unlock(&chewToy_mut);
	pthread_mutex_unlock(&mutt_mut);
	pthread_exit(NULL);
}





