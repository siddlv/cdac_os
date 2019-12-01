#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

#define BUFFER_SIZE 1024
int main() 
{ 
	int fd1[2], fd2[2]; 
	int input[2];
	int i = 0;
	
	printf("Enter two integers, press enter after one\n");
	while(i < 2){
		scanf("%d", &input[i]);
		++i;
	}

	int buffer[BUFFER_SIZE]; 
	pid_t p; 

	if (-1 == pipe(fd1)) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 
	if (-1 == pipe(fd2)) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 

	p = fork(); 

	if (p < 0) 
	{ 
		fprintf(stderr, "fork Failed" ); 
		return 1; 
	} 

	else if (p > 0) 
	{ 
		int parent_buff[BUFFER_SIZE]; 

		close(fd1[0]); 

		printf("Parent writing to pipe | Parent PID: %d\n", getpid());
		
		write(fd1[1], input, BUFFER_SIZE); 
		close(fd1[1]); 

		wait(NULL); 

		close(fd2[1]); 

		read(fd2[0], parent_buff, BUFFER_SIZE); 
		printf("%d + %d = %d\n", input[0], input[1], parent_buff[0]); 
		printf("Parent read from pipe | Parent PID: %d\n", getpid());
		close(fd2[0]); 
	} 

	else
	{ 
		int child_buff[100]; 
		int sum[BUFFER_SIZE];
		close(fd1[1]); 
	
		printf("Child reading from pipe | PID: %d\n", getpid());
		read(fd1[0], child_buff, BUFFER_SIZE); 

		printf("integers to add: %d + %d\n", child_buff[0], child_buff[1]);
        sum[0] = child_buff[0] + child_buff[1];
		
		printf("Child writing to pipe | PID: %d\n", getpid());
		close(fd1[0]); 
		close(fd2[0]); 
		write(fd2[1], sum, BUFFER_SIZE); 
		close(fd2[1]); 
		exit(0); 
	} 
}
