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
	struct mq_attr mq_at;

	mq_at.mq_flags = 0 ;
	mq_at.mq_maxmsg = 1;
	mq_at.mq_msgsize = SIZE;
	mq_at.mq_curmsgs = 0;

	mq = mq_open("/message", O_CREAT | O_RDWR,
	             S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &mq_at);

	if (-1 == mq)
	{
		perror("Open Error ");
		return 0;
	}

	mq_send(mq, "Hello, this is a message", SIZE, 0);
	mq_close(mq);

	return 0;
}