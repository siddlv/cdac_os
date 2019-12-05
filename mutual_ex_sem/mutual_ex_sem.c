#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem_a;
sem_t sem_b;
int count = 0;

void* input(void* data) {
	while (1) {
		sem_wait(&sem_a);
		sem_wait(&sem_b);
		count++;
		printf("INC= %d\n", count);
		sem_post(&sem_a);
		sem_post(&sem_b);
	}
}

void* proc(void* data) {
	while (1) {
		sem_wait(&sem_a);
		sem_wait(&sem_b);
		count--;
		printf("DEC= %d\n", count);
		sem_post(&sem_a);
		sem_post(&sem_b);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t id1, id2;

	sem_init(&sem_a, 0, 1);
	sem_init(&sem_b, 0, 1);

	pthread_create(&id1, NULL, input, NULL);
	pthread_create(&id2, NULL, proc, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	sem_destroy(&sem_a);
	sem_destroy(&sem_b);

	return 0;
}