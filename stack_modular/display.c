 #include<stdio.h>
 extern int MAX;
extern int arr[10];
extern int top;
void display(int top)
{
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	while(top!=-1)
	{
		printf("%d ",arr[top]);
		top=top-1;
	}
}

