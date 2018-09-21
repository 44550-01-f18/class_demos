#include <stdio.h>

int main(int argc, char* argv[])
{
	int ages [5];
	int bob = 42;
	ages[0] = 10;
	ages[1] = 24;
	ages[2] = 30;
	ages[3] = 42;
	ages[4] = 17;
	ages[5] = 15;
	// ages = [10, 24, 30, 42, 17]
	
	for (int i=0; i<5; i++)
		printf("%d ", ages[i]);
	printf("\a\n");
	return 0;
}
