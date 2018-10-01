#include <stdio.h>

void do_a_thing(void (*my_func) ());
void foo();
void bar();

int main(int argc, char* argv[])
{
	do_a_thing(foo);
	do_a_thing(bar);
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
