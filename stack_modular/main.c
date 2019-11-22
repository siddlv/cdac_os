#include<stdio.h>
#include<stdlib.h>
#include"header.h"
int  MAX=10;
int stack_arr[10];
int top=-1;

 void main()
 {
     int choice,item;
     while(1)
     {
         printf("1.push\n2.pop\n3.display\n4.quit\n");
         printf("Enter your choice:");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
                    printf("Enter the item to be pushed\n");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2:
                    item=pop();
                    printf("popped item is %d\n",item);
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    exit(1);
                    
         }
     }
 }