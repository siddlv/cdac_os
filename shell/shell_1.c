#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER 1024

int main(void) {
    char line[BUFFER];

    while (1) {
        printf("$ ");
        if (!fgets(line, BUFFER, stdin)) break;
        char *p = strchr(line, '\n');
        if (p) *p = 0;
        if (strcmp(line, "exit") == 0) break;
        char *args[] = {line, (char*)0};
        int pid = fork();             //fork child
        if (pid == 0) {            //Child
            execvp(line, args);
            perror("exec");
            exit(1);
        } else {                    //Parent
            wait(NULL);
        }
    }

    return 0;
}