#include<stdio.h>
#include<pthread.h>
int count = 0;
void* incThread(void* data)
{
	while (1)
	{
		count++;
		printf("INC= %d\n", count);
	}
}
void* decThread(void* data)
{
	while (1)
	{
		count--;
		printf("DEC= %d\n", count);
	}
}
int main()
{
	pthread_t id1;
	pthread_t id2;
	pthread_create(&id1, NULL, incThread, NULL);
	pthread_create(&id2, NULL, decThread, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	return 0;
}