#include <stdio.h>
#include "arith.h"

int main(int argc, char const *argv[])
{
	printf("%d\n", add(20, 10));
	printf("%d\n", sub(20, 10));
	printf("%d\n", mul(20, 10));
	printf("%d\n", div(20, 10));
	return 0;
}