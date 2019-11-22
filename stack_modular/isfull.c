extern int  MAX;
extern int stack_arr[10];
extern int top;
int isfull()
{
    if(top==MAX-1)
    return 1;
    else 
    return 0;
}