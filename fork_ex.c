#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int cpid = fork();
	if (cpid > 0)
	{
		printf("In parent, child id is %d\n", cpid);
	}
	else
	{
		printf("In child, cpid is %d\n", cpid);
	}
	return 0;
}
