#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//void batter(int sig);
void ping(int sig);
void pong(int sig);
int cpid;
int main(int argc, char* argv[])
{
	cpid = fork();
	if (cpid == 0)
	{
		signal(SIGUSR1, ping);
		while(1);
	}
	else
	{
		//for(int i=0; i<1000000; i++);
		sleep(1);
		signal(SIGUSR2, pong);
		kill(cpid, SIGUSR1);
		while(1);
	}
	sleep(1);
	kill(cpid, SIGINT);
	sleep(1);
	return 0;
}

void ping(int sig)
{
	printf("Ping!\n");
	kill(getppid(), SIGUSR2);
}

void pong(int sig)
{
	printf("Pong!\n");
	sleep(1);
	kill(cpid, SIGUSR1);

}


