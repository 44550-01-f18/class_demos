#include <stdio.h>
#include "header.h"
//function definitions
void greet(int id)
{
	printf("Greetings agent %d\n", id);
}

int foo()
{
	return bar();
}

int bar()
{
	return 24;
}
