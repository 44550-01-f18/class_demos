#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	for (int i=0; i<10; i++)
	{
		srand(time(0));
		printf("%d ", rand());
	}
	printf("\n");
	return 0;
}
