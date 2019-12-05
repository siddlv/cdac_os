#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode  constants*/
#include <fcntl.h>
#include <unistd.h>

int* countr;

int main(int argc, char const *argv[])
{
	int sh_m;

	sh_m = shm_open("/sh_mem", O_RDWR,
	                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	ftruncate(sh_m, sizeof(int));

	countr = (int *)mmap(NULL, sizeof(int),
	                     PROT_READ | PROT_WRITE, MAP_SHARED, sh_m, 0);

	while (1) {
		printf("Count: %d\n", *countr);
	}

	return 0;
}