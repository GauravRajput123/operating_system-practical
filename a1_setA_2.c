#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Child Process ID: %d\n", getpid());

        // Increase priority of child process using nice()
        nice(-10); // Decreasing the nice value increases priority
    }
    else if (pid > 0)
    {
        // Parent process
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }
    else
    {
        // Forking error
        printf("Forking failed\n");
    }

    return 0;
}