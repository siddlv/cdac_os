#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <errno.h>
#include <string.h>

#define SIZE 64

int main(int argc, char const *argv[])
{
	mqd_t mq;
	int prio, res;
	char rec_buffer[64];

	struct mq_attr mq_at;

	mq_at.mq_flags = 0 ;
	mq_at.mq_maxmsg = 1;
	mq_at.mq_msgsize = SIZE;
	mq_at.mq_curmsgs = 0;

	mq = mq_open("/message", O_RDWR,
	             S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &mq_at);

	res = mq_receive(mq, rec_buffer, SIZE, &prio);

	if (-1 == res)
	{
		perror("Read Error ");
		return 0;
	}

	printf("Received Message = %s\n", rec_buffer);

	return 0;
}