// parent program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6}; // Input array

    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        char *args[] = {"./child", NULL}; // Executable file name
        execv(args[0], args);
        printf("Child process failed to execve.\n");
    }
    else if (pid > 0)
    {
        // Parent process
        wait(NULL); // Wait for child to complete
        printf("Parent process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Sorting array...\n");
        qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compare);
        printf("Sorted array: ");
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        // Forking error
        printf("Forking failed\n");
    }

    return 0;
}