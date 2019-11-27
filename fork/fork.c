#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>

int main() 
{ 	
	printf("hello world pid : %d \n", getpid());
	fork();
	printf("hello world pid : %d \n", getpid());  
	fork();
	printf("hello world pid : %d \n", getpid()); 
	return 0; 
}