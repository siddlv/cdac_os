#include<stdlib.h>
#include<stdio.h>
int* create_block(int n)
{
	int *temp = malloc(n * sizeof(int));
	printf("created at %p\n", temp);
	if (temp == NULL)
	{
		perror("error malloc\n");
		exit(EXIT_FAILURE);
	}
	return temp;
}