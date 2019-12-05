#include<stdio.h>
#include<pthread.h>

int count = 0;

pthread_mutex_t count_mutex;
pthread_mutexattr_t mat;

void* incThread(void* data)
{
	while (1)
	{
		pthread_mutex_lock (&count_mutex);
		pthread_mutex_lock (&count_mutex);
		pthread_mutex_lock (&count_mutex);
		count++;
		printf("INC= %d\n", count);
		pthread_mutex_unlock (&count_mutex);
		pthread_mutex_unlock (&count_mutex);
		pthread_mutex_unlock (&count_mutex);
	}
}

void* decThread(void* data)
{
	while (1)
	{
		pthread_mutex_lock (&count_mutex);
		pthread_mutex_lock (&count_mutex);
		pthread_mutex_lock (&count_mutex);
		count--;
		printf("DEC= %d\n", count);
		pthread_mutex_unlock (&count_mutex);
		pthread_mutex_unlock (&count_mutex);
		pthread_mutex_unlock (&count_mutex);
	}
}

int main()
{
	pthread_t id1, id2;

	pthread_mutexattr_init (&mat);
	pthread_mutexattr_settype (&mat, PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutex_init (&count_mutex, &mat);

	pthread_create (&id1, NULL, incThread, NULL);
	pthread_create (&id2, NULL, decThread, NULL);

	pthread_join (id1, NULL);
	pthread_join (id2, NULL);

	pthread_mutex_destroy (&count_mutex);

	return 0;
}