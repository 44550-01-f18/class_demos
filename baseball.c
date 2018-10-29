#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void batter(int sig);

int main(int argc, char* argv[])
{
	int cpid = fork();
	if (cpid == 0)
	{
		signal(SIGUSR1, batter);
		while(1);
	}
	else
	{
		//for(int i=0; i<1000000; i++);
		sleep(1);
		for (int i=0; i<9; i++)
		{
			sleep(1);
			kill(cpid, SIGUSR1);
		}
	}
	sleep(1);
	kill(cpid, SIGINT);
	sleep(1);
	return 0;
}

void batter(int sig)
{
	static int num = 0;
	num += 1;
	if (num == 4) num = 1;
	printf("STEEEEEEEEERIKE %d\n", num);
}


