#include<stdio.h>
#include"stackheader.h"
#include<stdlib.h>

int MAX = 8;
int arr[8];
int top=-1;

int main(){
  int tasks;
  int tasks_arr[8];
  int priority_task = 0;

  printf("Enter the 8 bit task byte as an integer in binary:\n");
  scanf("%d", &tasks);

  for (int i = 7; i >= 0; --i)
  {
    tasks_arr[i] = tasks % 10;
    tasks /= 10;
  }

  for (int i = 0; i < 8; ++i)
  {
    if (tasks_arr[i] == 1)
    {
      push(i);
    }
  }

  priority_task = peek();
  printf("The task to be scheduled is %d\n", priority_task + 1);

  return 0;
}