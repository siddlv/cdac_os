#include<stdio.h>
 extern int MAX;
extern int arr[10];
extern int top;
int peek()
{
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	return arr[top];
}
