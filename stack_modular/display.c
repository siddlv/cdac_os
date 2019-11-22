
extern int  MAX;
extern int stack_arr[10];
extern int top;
void display()
{
    int i;
    if(isempty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack_arr[i]);
    }
}