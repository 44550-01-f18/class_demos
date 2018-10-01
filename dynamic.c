#include <stdio.h>
#include <stdlib.h>

void cleanup(int ** p);

int main(int argc, char* argv[])
{
/*	printf("%d arguments\n", argc);
	for (int i=0; i<argc; i++)
		printf("%s\n", argv[i]); */
	int * arry;
	int ** arry_ptr;
	//printf("0x%X\n", arry);
	arry = (int *)malloc(50 * sizeof(int));
	arry[0] = 10;
	arry[1] = 20;
	printf("0x%X\n", arry);
	printf("%d\n", arry[0]);

	printf("%d\n", *arry);
	printf("0x%X\n", arry);
	printf("0x%X\n", &arry[0]);

	arry_ptr = & arry;
	printf("arry_ptr: 0x%X\n", arry_ptr);
	printf("*arry_ptr: 0x%X\n", *arry_ptr);
	//cleanup(&arry);
	printf("0x%X\n", arry);
	//cleanup(&arry);
	free(arry);
	free(arry);
	return 0;
}

void cleanup(int ** p)
{
	if (*p != NULL)
		free(*p);
	*p = NULL;
}
