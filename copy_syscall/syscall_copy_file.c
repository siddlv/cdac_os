#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	int fd1, fd2, w_return, r_return, c_return1, c_return2;
	const int size = 100;
	char buf[size];

	//opening the file1 to be copied
	fd1 = open("file1.txt", O_RDONLY,
	           S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fd1 != -1)
	{
		//read from the file
		r_return = read(fd1, buf, size);
	}
	else
		// if open() throws an error
		perror("Open File1 Error ");

	if (r_return == -1)
	{
		//if read() throws an error
		perror("Read File1 Error ");
	}

	//opening file2 to write copy the contents of file1
	fd2 = open("file2.txt", O_CREAT | O_WRONLY,
	           S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fd2 != -1)
	{
		// writing data buf to the file2 of size 6
		w_return = write(fd2, buf, size);
	}
	else
		// if open() throws an error
		perror("Open File2 Error ");

	if (w_return == -1)
	{
		//if write() throws an error
		perror("Write File2 Error ");
	}

	// closing the opened file
	c_return1 = close(fd1);
	c_return2 = close(fd2);

	if (c_return1 == -1 || c_return2 == -1)
	{
		//if close throws an error
		perror("Close Error ");
	}

	return 0;
}