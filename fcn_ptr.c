#include <stdio.h>

void do_a_thing(void (*my_func) ());
void foo();
void bar();

int square(int x);
int cube(int x);

void do_another_thing(int (*my_func) (int a));

int main(int argc, char* argv[])
{
	do_a_thing(foo);
	do_a_thing(bar);
	do_another_thing(square);
	do_another_thing(cube);
	return 0;
}

void foo()
{
	printf("I'm in foo!\n");
}

void bar()
{
	printf("YARRRRRRRR\n");
}

void do_a_thing(void (*my_func) ())
{
	my_func();
}

void do_another_thing(int (*my_func) (int a))
{
	printf("%d\n", my_func(4));
}
int square(int x)
{
	return x*x;
}
int cube(int x)
{
	return x*x*x;
}
