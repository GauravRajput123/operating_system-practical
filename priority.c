// priority scheduling algorithm with non-preemption
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    printf("Enter Number of Processes:");
    scanf("%d", &n);
    int burst[n], priority[n], index[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority Value for process %d:", i + 1);
        scanf("%d%d", &burst[i], &priority[i]);
        index[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        int temp = priority[i], m = i;
        for (int j = i; j < n; j++)
        {
            if (priority[j] > temp)
            {
                temp = priority[j];
                m = j;
            }
        }
        swap(&priority[i], &priority[m]);
        swap(&burst[i], &burst[m]);
        swap(&index[i], &index[m]);
    }
    int t = 0;
    printf("order of process execution is\n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d is executed from %d to %d\n", index[i], t, t + burst[i]);
        t += burst[i];
    }
    printf("\n");
    printf("process id\tBurst Time\tWait Time\n");
    int wait_time = 0;
    int total_wait_time = 0;
    for (int i = 0; i < n; i++)
    {
        printf("p%d\t\t%d\t\t%d\n", index[i], burst[i], wait_time);
        total_wait_time += wait_time;
        wait_time += burst[i];
    }
    float avg_wait_time = (float)total_wait_time / n;
    printf("Average waiting time is %f\n", avg_wait_time);
    int total_Turn_Around = 0;
    for (int i = 0; i < n; i++)
    {
        total_Turn_Around += burst[i];
    }
    float avg_Turn_Around = (float)total_Turn_Around / n;
    printf("Average TurnAround time is %f\n", avg_Turn_Around);
    return 0;
}
