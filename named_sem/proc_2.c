#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>


#define SEM_NAME1 "/nm1"
#define SEM_NAME2 "/nm2"


int *count;
int *a;

int main(int argc, char const *argv[])
{

	int fd;

	fd = shm_open(SEM_NAME1, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	ftruncate(fd, 3 * sizeof(int));
	count = (int *)mmap(NULL, 3 * sizeof(int),
	                    PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	sem_t *sem1 = sem_open(SEM_NAME1, O_CREAT | O_RDWR,
	                       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, 0);


	sem_t *sem2 = sem_open(SEM_NAME2, O_CREAT | O_RDWR,
	                       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	a = count;

	sem_init(sem2, 1, 0);

	printf("Waiting for integers to be inserted\n");

	while (1) {

		sem_wait(sem2);

		printf("First integer: %d\n", *(count));
		printf("Second integer: %d\n", *(count + 1));

		int sum = *a + *(a + 1);

		*(a + 2) = sum;

		printf("Sum: %d\n", sum);

		sem_post(sem1);
	}
	return 0;
}