#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>

int main() 
{ 	
	fork(); 
	fork();
	printf("hello world pid : %d \n", getpid()); 
	return 0; 
}