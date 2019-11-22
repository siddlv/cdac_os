#include<stdio.h>
 extern int MAX;
extern int arr[10];
extern int top;
void push(int ele)
{
	if(top==MAX-1)
	{
		printf("stack overflow\n");
		return;
	}

		top=top+1;
		arr[top]=ele;
}