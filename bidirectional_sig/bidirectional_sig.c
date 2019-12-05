#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem_in_proc;
sem_t sem_proc_in;
int a, b;

void* input(void* data) {
	while (1) {
		sem_wait(&sem_proc_in);
		printf("Enter two integers to add\n");
		scanf("%d %d", &a, &b);
		printf("%d %d\n", a, b);
		sem_post(&sem_in_proc);
	}
}

void* proc(void* data) {
	while (1) {
		sem_wait(&sem_in_proc);
		int sum;
		sum = a + b;
		printf("Sum = %d\n", sum);
		sem_post(&sem_proc_in);
	}
}


int main(int argc, char const *argv[])
{
	pthread_t id1, id2;

	sem_init(&sem_in_proc, 0, 0);
	sem_init(&sem_proc_in, 0, 1);

	pthread_create(&id1, NULL, input, NULL);
	pthread_create(&id2, NULL, proc, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	sem_destroy(&sem_in_proc);
	sem_destroy(&sem_proc_in);

	return 0;
}