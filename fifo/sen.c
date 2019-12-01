#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<errno.h>
#include <fcntl.h>
#include<stdlib.h>
#include <unistd.h>

// #define BUFF_SIZE 2048


int main()
{
    int fds;
    int buff[2] = {1,2};
    int fdc;
    int ans;

    fds = open("desdfifo1",O_RDWR);

    if(-1 == fds)
    {
        perror("error1");
        exit(EXIT_FAILURE);
    }

    fds = write(fds,buff,sizeof(buff));
    if(-1 == fds)
    {
        perror("error2");
        exit(EXIT_FAILURE);
    }

    close(fds);



    fdc = open("desdfifo2",O_RDWR);

    if(-1 == fdc)
    {
        perror("error3");
        exit(EXIT_FAILURE);
    }

    fdc = read(fdc,&ans,sizeof(ans));
    if(-1 == fdc)
    {
        perror("error4");
        exit(EXIT_FAILURE);
    }
    printf("%d",ans);
    
    close(fdc);


    return 0;
}