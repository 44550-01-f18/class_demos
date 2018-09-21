#include <stdio.h>

int main(int argc, char* argv[])
{
	unsigned int temperature = -10;
	int countup = 0;
	if (temperature  < 45)
	{
		printf("It's cold!\n");
	}
	else if (temperature > 75)
	{
		printf("It's too hot!\n");
	}
	else
	{
		printf("Just right!\n");
	}
	printf("%u\n", temperature);
	for (int i=0; i<10; i++)
		printf("%d\n", i);
	while (countup <10)
	{
		printf("%d\n", countup);
		countup += 1;
	}
	countup = 0;
	do
	{
		printf("%d\n", countup);
		countup += 1;
	} while (countup < 10);

	return 0;
}
