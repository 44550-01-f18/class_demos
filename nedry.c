#include <signal.h>
#include <stdio.h>

void dennis(int signal);

int main(int argc, char* argv[])
{
	signal(SIGINT, dennis);
	while(1);
	return 0;
}

void dennis(int signal)
{
	printf("Ah ah ah, you didn't say the magic word!\n");
}
