#include<stdio.h>
#include <pthread.h>

void *addthread(void* data)
{
	int *k = data;
	printf("The Sum iS %d", *k + * (k + 1));
}
int main()
{
	pthread_t id;
	int a[2] = {7, 6};
	
	pthread_create(&id, NULL, addthread, a);
	pthread_join(id, NULL);

	return 0;
}
