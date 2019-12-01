#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<errno.h>
#include <fcntl.h>
#include<stdlib.h>
#include <unistd.h>

//#define BUFF_SIZE 2048

int main()
{
    int buff[2];
    int fdc;
    int fds;

    fdc = open("desdfifo1",O_RDWR);

    if(-1 == fdc)
    {
        perror("error5");
        exit(EXIT_FAILURE);
    }

    fdc = read(fdc,buff,sizeof(buff));
    if(-1 == fdc)
    {
        perror("error6");
        exit(EXIT_FAILURE);
    }
    printf("%d %d",buff[0],buff[1]);
    
    close(fdc);



    fds = open("desdfifo2",O_RDWR);

    if(-1 == fds)
    {
        perror("error7");
        exit(EXIT_FAILURE);
    }
   int  sum= buff[0]+buff[1];
    fds = write(fds,&sum,sizeof(sum));
    if(-1 == fds)
    {
        perror("error8");
        exit(EXIT_FAILURE);
    }

    close(fds);

    return 0;
}