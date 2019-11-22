
extern int  MAX;
extern int stack_arr[10];
extern int top;
void push(int item)
{
    if(isfull())
    {
        printf("Stack overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=item;
}