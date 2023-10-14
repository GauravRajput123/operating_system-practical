#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Child process:\n");

        printf("Child PID: %d\n", getpid());
        printf("Parent PID (PPID) of child: %d\n", getppid());
        sleep(5); // Simulate some work in the child process
        printf("Child process finished.\n");
    }
    else if (pid > 0)
    {
        // Parent process
        printf("Parent process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID of parent: %d\n", pid);
        printf("Parent process terminating...\n");
    }
    else
    {
        // Forking error
        printf("Forking failed\n");
    }

    return 0;
}