#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        char *args[] = {"./child_program", NULL}; // Replace with actual program name
            execv(args[0], args);
        printf("Child process failed to execute.\n");
    }
    else if (pid > 0)
    {
        // Parent process
        wait(NULL); // Wait for child to complete
        printf("I am parent.\n");
    }
    else
    {
        // Forking error
        printf("Forking failed\n");
    }

    return 0;
}