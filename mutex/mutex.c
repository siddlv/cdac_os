#include<stdio.h>
#include<pthread.h>

int count = 0;

pthread_mutex_t count_mutex;

void* incThread(void* data)
{
	while (1)
	{	
		pthread_mutex_lock(&count_mutex);
		count++;
		printf("INC= %d\n", count);
		pthread_mutex_unlock (&count_mutex);
	}
}
void* decThread(void* data)
{
	while (1)
	{	
		pthread_mutex_lock (&count_mutex);
		count--;
		printf("DEC= %d\n", count);
		pthread_mutex_unlock (&count_mutex);
	}
}
int main()
{
	pthread_t id1;
	pthread_t id2;

	pthread_mutex_init (&count_mutex, NULL);

	pthread_create(&id1, NULL, incThread, NULL);
	pthread_create(&id2, NULL, decThread, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	pthread_mutex_destroy (&count_mutex);

	return 0;
}