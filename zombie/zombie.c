#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>

int main() 
{ 	
	pid_t id;

	id = fork();

	if (0 == id)
	{
		printf("Child process : %d Parent process : %d\n", getpid(), getppid());
	}
	else{
		printf("Parent process : %d \n", getpid());
		sleep(10);
	} 
	return 0; 
}