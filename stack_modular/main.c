#include<stdio.h>
#include"stackheader.h"
#include<stdlib.h>
int MAX = 10;
 int arr[10];
 int top=-1;
int main()
{

        int ch,ele,item;
        while(1)
        {
        printf("\n 1.To push:\n 2.To pop:\n 3.To display:\n 4.To peek:\n");
        scanf("%d",&ch);
              switch(ch)
            {
              	  case 1:
              		  printf("enter the element\n");
              		  scanf("%d",&ele);
              		  push(ele);

              		  break;
              	  case 2:
              		 item= pop();
              		  break;
              	  case 3:
              		  display(top);
              		  break;
              	  case 4:
              		  printf("item at the top is %d\n",peek());
                	  break;
              	  default:
              		  printf("wrong choice:\n");
            }


             }
        return 0;
        }