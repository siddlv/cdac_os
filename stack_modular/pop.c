
extern int  MAX;
extern int stack_arr[10];
extern int top;
int pop(void)
{
    int item;
if(isempty())
{
    printf("Stack is empty");
    return;
}
item=stack_arr[top];
top=top-1;
return item;
}