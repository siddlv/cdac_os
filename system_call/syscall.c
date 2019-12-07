#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	int fd, w_return_size, return_close;
	const void *buf = "hello\n";

	//opening the file, if it doesnt exists then creating it and giving approriate permissions
	fd = open("syscall.txt", O_CREAT | O_WRONLY, 
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fd != -1)
	{
		// writing data buf to the file of size 6
		w_return_size = write(fd, buf, 6);
	}
	else
		// if open() throws an error
		perror("Error ");

	if (w_return_size == -1)
	{	
		//if write() throws an error
		perror("Error ");
	}

	// closing the opened file
	return_close = close(fd);

	if (return_close == -1)
	{	
		//if close throws an error
		perror("Error ");
	}

	return 0;
}