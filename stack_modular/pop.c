#include<stdio.h>
 extern int MAX;
extern int arr[10];
extern int top;
int pop()
{
 int item;
 if(top==-1)
	{
	 printf("stack is underflow\n");
    }
    item= arr[top];
    top=top-1;
    return item;
}