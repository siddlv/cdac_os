#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode  constants*/
#include <fcntl.h>            /* For O_* constants*/
#include <unistd.h>

int *count;

int main(int argc, char const *argv[])
{
	int sh_m;

	sh_m = shm_open("/sh_mem", O_CREAT | O_RDWR,
	                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	ftruncate(sh_m, sizeof(int));

	count = (int *)mmap(NULL, sizeof(int),
	                    PROT_READ | PROT_WRITE, MAP_SHARED, sh_m, 0);

	*count = 0;

	while (1) {
		(*count)++;
		sleep(1);
	}
	return 0;
}