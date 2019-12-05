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
int *ptr;
int a, b, c;

int main(int argc, char const *argv[])
{

	int fd;

	fd = shm_open(SEM_NAME1, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	ftruncate(fd, 3 * sizeof(int));
	count = (int *)mmap(NULL, 3 * sizeof(int),
	                    PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	sem_t *sem1 = sem_open(SEM_NAME1, O_CREAT | O_RDWR,
	                       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	sem_t *sem2 = sem_open(SEM_NAME2, O_CREAT | O_RDWR,
	                       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	sem_init(sem1, 1, 1);

	while (1) {

		sem_wait(sem1);

		ptr = count;
		printf("Enter the first integer:\n");
		scanf("%d", &a);
		*ptr = a;
		ptr++;
		printf("Enter the second integer:\n");
		scanf("%d", &b);
		*ptr = b;
		sem_post(sem2);
		sem_wait(sem1);
		printf("Sum: %d\n", *(count + 2));
		sem_post(sem2);
	}
	return 0;
}