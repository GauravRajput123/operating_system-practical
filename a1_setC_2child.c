#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
printf("I am Child Process\n");
printf("Child Process ID: %d\n", getpid());

return 0;
}