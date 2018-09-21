#include <stdio.h>

void swap(int a, int b);

int main(int argc, char* argv[])
{
	int a = 6;
	int b = 15;
	// declare a pointer;
	int * ptr;
	ptr = &a;
/*
	printf("%d\n", a);
	printf("%d\n", &a);
	printf("%d\n", *ptr);
	*/

	printf("a = %d, *ptr = %d\n", a, *ptr); 
	a = 10;
	printf("a = %d, *ptr = %d\n", a, *ptr); 
	printf("Address is: 0x%X\n", ptr);
	ptr = &b;
	printf("a = %d, *ptr = %d\n", a, *ptr); 
	printf("Address is: 0x%X\n", ptr);
	printf("b = %d, *ptr = %d\n", b, *ptr);
	*ptr = 42;
	printf("b = %d, *ptr = %d\n", b, *ptr);
	//---
	printf("a = %d, b = %d\n", a, b);
	printf("After swap:\n");
	swap(a, b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

void swap(int a, int b)
{
	int temp = b;
	b = a;
	a = temp;
}










