#include<stdio.h>
#include <unistd.h>

int main()
{
  char cmd[1024];
  int id;
  while (1)
  {
    printf("> ");
    scanf("%s", cmd);
    id = fork();
    if (0 == id)
    {
      execlp((const char*)cmd, (const char*)cmd, (const char*)NULL);
    }
  }
  return 0;
}
